#include <QApplication>
#include <QFont>
#include <QLCDNumber>
#include <QLabel>
#include <QMenu>
#include <QPushButton>
#include <QSound>
#include <QTreeWidgetItem>
#include <QVBoxLayout>

#include <iostream>

auto main(int argc, char *argv[]) -> int {
  QApplication app(argc, argv);

  QWidget widget;

  QPushButton button("&Reset");
  QMenu menu;
  menu.addMenu("un");
  menu.addMenu("deux");
  menu.addMenu("trois");
  button.setMenu(&menu);
  button.setToolTip("aide me voici");
  button.setFont(QFont("Times", 10, QFont::Bold));
  button.setCursor(Qt::PointingHandCursor);
  button.setIcon(QIcon("/home/blackpc/Downloads/hibou.jpg"));
  button.show();

  auto *treeWidget = new QTreeWidget();
  treeWidget->setColumnCount(2);
  QList<QTreeWidgetItem *> items;
  for (int i = 0; i < 10; ++i)
    items.append(new QTreeWidgetItem(static_cast<QTreeWidget *>(nullptr),
                                     QStringList(QString("item: %1").arg(i))));
  treeWidget->insertTopLevelItems(0, items);

  auto *cities = new QTreeWidgetItem(treeWidget);
  cities->setText(0, ("Cities"));
  auto *osloItem = new QTreeWidgetItem(cities);
  osloItem->setText(0, ("Oslo"));
  osloItem->setText(1, ("Yes"));

  QLCDNumber lcd;
  lcd.display(42);

  QLabel label;
  label.setText("coucou je suis un label");

  QVBoxLayout layout;
  layout.addWidget(&button);
  layout.addWidget(treeWidget);
  layout.addWidget(&lcd);
  layout.addWidget(&label);
  widget.setLayout(&layout);

  std::cout << '|' << button.objectName().toStdString() << '|' << std::endl;

  widget.show();

  return app.exec();
}
