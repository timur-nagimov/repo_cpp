#include "schedule.h"
#include "mainwindow.h"
#include "calendaractivity.h"
#include "sets.h"
#include "ui_schedule.h"
#include <QSqlTableModel>
#include <QStyledItemDelegate>
#include <QSqlRecord>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QSignalBlocker>
#include <QItemDelegate>
#include <QComboBox>
#include <QMessageBox>

class ValidatingComboBoxDelegate : public QItemDelegate {
public:
    ValidatingComboBoxDelegate(const QStringList &items, QObject *parent = 0)
        : QItemDelegate(parent), m_items(items) {}

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &,
                          const QModelIndex &) const override {
        QComboBox *editor = new QComboBox(parent);
        editor->addItems(m_items);
        return editor;
    }

    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override {
        QComboBox *comboBox = static_cast<QComboBox*>(editor);
        QString value = comboBox->currentText();
        if (!m_items.contains(value)) {
            QMessageBox::warning(nullptr, "Неверное значение", "Введенное значение не найдено в списке.");
            return;
        }
        model->setData(index, value, Qt::EditRole);
    }

private:
    QStringList m_items;
};



schedule::schedule(QString username, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::schedule),
    model(new QSqlTableModel(this)),  // Инициализация model
    m_username(username)

{
    //QTimer::singleShot(0, this, SLOT(showFullScreen()));

    ui->setupUi(this);
    this->setWindowTitle("FitApp - Упражнения");
    model->setTable("exercises");
    model->select();

    // Настройка QTableView
    ui->tableView->setModel(model);
    ui->tableView->setItemDelegate(new QStyledItemDelegate());
    ui->tableView->hideColumn(0); // Скрываем столбец с индексом 0 (id)

    // В конструкторе schedule
    QStringList muscleGroups = {"Ноги", "Спина", "Грудная клетка", "Дельтовидные", "Руки", "Живот"};
    QStringList difficulties = {"Продвинутый", "Средний", "Начальный"};

    ui->tableView->setItemDelegateForColumn(2, new ValidatingComboBoxDelegate(muscleGroups, this));
    ui->tableView->setItemDelegateForColumn(3, new ValidatingComboBoxDelegate(difficulties, this));

     // Инициализация muscleGroupComboBox и difficultyComboBox
    ui->muscleGroupComboBox->clear();
    ui->muscleGroupComboBox->addItems(muscleGroups);

    ui->difficultyComboBox->clear();
    ui->difficultyComboBox->addItems(difficulties);


    // Растяжение ячеек на весь объект
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Изменение заголовков столбцов
    model->setHeaderData(1, Qt::Horizontal, tr("Название"));
    model->setHeaderData(2, Qt::Horizontal, tr("Группа Мыщц"));
    model->setHeaderData(3, Qt::Horizontal, tr("Сложность"));

}

schedule::schedule(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::schedule),
    model(new QSqlTableModel(this)),
    m_username("") // Инициализация с пустой строкой
{
    ui->setupUi(this);
    // Дополнительная инициализация, если требуется
}

schedule::~schedule()
{
    delete ui;
}

void schedule::on_saveButton_clicked()
{
    if (model != nullptr) {
        model->submitAll();
        qDebug() << "Изменения сохранены.";
    } else {
        qDebug() << "Ошибка: model не инициализирована.";
    }
}



void schedule::on_cancelButton_clicked()
{
    if (model != nullptr) {
        model->revertAll();  // Отменяет все незафиксированные изменения
        qDebug() << "Изменения отменены.";
    } else {
        qDebug() << "Ошибка: model не инициализирована.";
    }
}


void schedule::on_addButton_clicked() {
    QString exerciseName = ui->exerciseNameLineEdit->text();
    QString muscleGroup = ui->muscleGroupComboBox->currentText();
    QString difficulty = ui->difficultyComboBox->currentText();

    if (exerciseName.isEmpty()) {
        QMessageBox::warning(this, "Предупреждение", "Введите название упражнения.");
        return;
    }

    // Подготовка и выполнение запроса для проверки на существование упражнения
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM exercises WHERE name = :name AND muscle_group = :muscle_group AND difficulty = :difficulty");
    checkQuery.bindValue(":name", exerciseName);
    checkQuery.bindValue(":muscle_group", muscleGroup);
    checkQuery.bindValue(":difficulty", difficulty);

    if (!checkQuery.exec()) {
        qDebug() << "Ошибка выполнения запроса: " << checkQuery.lastError().text();
            return;
    }

    if (checkQuery.next()) {
            int count = checkQuery.value(0).toInt();
            qDebug() << "Найдено записей: " << count;
            if (count > 0) {
                QMessageBox::warning(this, "Предупреждение", "Такое упражнение уже существует.");
                return;
            }
    } else {
            qDebug() << "Нет данных для чтения или ошибка запроса";
    }


    // Добавление записи
    QSqlRecord record = model->record();
    record.setValue("name", exerciseName);
    record.setValue("muscle_group", muscleGroup);
    record.setValue("difficulty", difficulty);

    if (!model->insertRecord(-1, record)) {
        QMessageBox::critical(this, "Ошибка", "Не удалось добавить упражнение.");
        return;
    }

    // Сохранение изменений и обновление таблицы
    model->submitAll();
    model->select();
}




void schedule::on_DeleteButton_clicked()
{
    QItemSelectionModel *select = ui->tableView->selectionModel();

    if (select->hasSelection()) {
        QModelIndexList selectedRows = select->selectedRows();
        for (int i = selectedRows.count() - 1; i >= 0; --i) {
                model->removeRow(selectedRows.at(i).row());
        }
        model->submitAll();
        model->select();
    } else {
        QMessageBox::warning(this, "Предупреждение", "Пожалуйста, выберите записи для удаления.");
    }
}


void schedule::on_authButton_clicked()
{
    // Создание и отображение главного окна авторизации
    MainWindow *mainwindow = new MainWindow();
    mainwindow->show();

    // Закрытие текущего окна
    this->close();
}


void schedule::on_setButton_clicked()
{
    sets *setsWindow = new sets(m_username);
    setsWindow->show();

    // Закрытие текущего окна
    this->close();
}


void schedule::on_timetableButton_clicked()
{
    // Создание и отображение главного окна авторизации
    CalendarActivity *calendaractiv = new CalendarActivity(m_username);
    calendaractiv->show();

    // Закрытие текущего окна
    this->close();
}

