#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QDialog>
#include<QMap>
#include <QItemDelegate>
#include <QComboBox>

namespace Ui {
class FrmMain;
}

class FrmMain : public QDialog
{
    Q_OBJECT

public:
    explicit FrmMain(QWidget *parent = 0);
    ~FrmMain();

protected:
    bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void on_btnMenu_Max_clicked();

private:
    Ui::FrmMain *ui;
    void initStyle();   //初始化无边框窗体
    void initForm();    //初始化窗体数据

    bool m_max;           //是否处于最大化状态
    QRect locatRect;     //鼠标移动窗体后的坐标位置
    QMap<QString, QString> mapStyle;
};

//类别列，利用QComboBox委托进行限制
class  SetpDelegate : public QItemDelegate
{
    Q_OBJECT
public :
    SetpDelegate(QObject *parent = 0): QItemDelegate(parent) { }
    QWidget *createEditor(QWidget *parent,  const QStyleOptionViewItem &option,
                          const  QModelIndex &index)  const
    {
        QComboBox *editor =  new  QComboBox(parent);
        editor->setStyleSheet("text-align:center;");
        editor->addItem( "CC Chargy" );
        editor->addItem( "CV Chargy" );
        editor->addItem( "CC DisChargy" );
        editor->addItem( "CP DisChargy" );
        editor->addItem( "GOTO" );
        editor->addItem( "CAMMAND" );
        editor->addItem( "STOP" );
        return  editor;
    }
    void  setEditorData(QWidget *editor,  const  QModelIndex &index)  const
    {
        QString text = index.model()->data(index, Qt::EditRole).toString();
        QComboBox *comboBox =  static_cast <QComboBox*>(editor);
        int  tindex = comboBox->findText(text);
        comboBox->setCurrentIndex(tindex);
    }
    void  setModelData(QWidget *editor, QAbstractItemModel *model,
                       const  QModelIndex &index)  const
    {
        QComboBox *comboBox =  static_cast <QComboBox*>(editor);
        QString text = comboBox->currentText();
        model->setData(index, text, Qt::EditRole);
    }
    void  updateEditorGeometry(QWidget *editor,
                               const  QStyleOptionViewItem &option,  const  QModelIndex &index) const
    {
        editor->setGeometry(option.rect);
    }
};


#endif // FRMMAIN_H
