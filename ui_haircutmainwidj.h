/********************************************************************************
** Form generated from reading UI file 'haircutmainwidj.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HAIRCUTMAINWIDJ_H
#define UI_HAIRCUTMAINWIDJ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HaircutMainWidj
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_8;
    QGroupBox *groupBox_DownloadeFile;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_ImagePath;
    QPushButton *pB_DownloadFIle;
    QRadioButton *rB_gray;
    QRadioButton *rB_red;
    QRadioButton *rB_hue;
    QRadioButton *rB_green;
    QRadioButton *rB_saturation;
    QRadioButton *rB_blue;
    QRadioButton *rB_value;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_2;
    QPushButton *pB_CreateMask;
    QFrame *line_2;
    QPushButton *pB_filter;
    QFrame *line;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBox_dilate;
    QLabel *label;
    QSpinBox *spinBox_dilatePower;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QSpinBox *sB_inpaintRadius;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QSpinBox *sB_treshold;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lbl_noiseArea;
    QSpinBox *sB_noiseArea;
    QPushButton *pB_paint;
    QFrame *line_3;
    QPushButton *pB_myPaint;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lbl_hairWidth;
    QSpinBox *sB_hairWidth;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HaircutMainWidj)
    {
        if (HaircutMainWidj->objectName().isEmpty())
            HaircutMainWidj->setObjectName(QStringLiteral("HaircutMainWidj"));
        HaircutMainWidj->resize(545, 461);
        centralWidget = new QWidget(HaircutMainWidj);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_8 = new QGridLayout(centralWidget);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        groupBox_DownloadeFile = new QGroupBox(centralWidget);
        groupBox_DownloadeFile->setObjectName(QStringLiteral("groupBox_DownloadeFile"));
        gridLayout = new QGridLayout(groupBox_DownloadeFile);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit_ImagePath = new QLineEdit(groupBox_DownloadeFile);
        lineEdit_ImagePath->setObjectName(QStringLiteral("lineEdit_ImagePath"));
        lineEdit_ImagePath->setReadOnly(true);

        horizontalLayout->addWidget(lineEdit_ImagePath);

        pB_DownloadFIle = new QPushButton(groupBox_DownloadeFile);
        pB_DownloadFIle->setObjectName(QStringLiteral("pB_DownloadFIle"));

        horizontalLayout->addWidget(pB_DownloadFIle);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 3);

        rB_gray = new QRadioButton(groupBox_DownloadeFile);
        rB_gray->setObjectName(QStringLiteral("rB_gray"));
        rB_gray->setChecked(true);

        gridLayout->addWidget(rB_gray, 1, 0, 1, 1);

        rB_red = new QRadioButton(groupBox_DownloadeFile);
        rB_red->setObjectName(QStringLiteral("rB_red"));

        gridLayout->addWidget(rB_red, 1, 1, 1, 1);

        rB_hue = new QRadioButton(groupBox_DownloadeFile);
        rB_hue->setObjectName(QStringLiteral("rB_hue"));

        gridLayout->addWidget(rB_hue, 1, 2, 1, 1);

        rB_green = new QRadioButton(groupBox_DownloadeFile);
        rB_green->setObjectName(QStringLiteral("rB_green"));

        gridLayout->addWidget(rB_green, 2, 1, 1, 1);

        rB_saturation = new QRadioButton(groupBox_DownloadeFile);
        rB_saturation->setObjectName(QStringLiteral("rB_saturation"));

        gridLayout->addWidget(rB_saturation, 2, 2, 1, 1);

        rB_blue = new QRadioButton(groupBox_DownloadeFile);
        rB_blue->setObjectName(QStringLiteral("rB_blue"));

        gridLayout->addWidget(rB_blue, 3, 1, 1, 1);

        rB_value = new QRadioButton(groupBox_DownloadeFile);
        rB_value->setObjectName(QStringLiteral("rB_value"));

        gridLayout->addWidget(rB_value, 3, 2, 1, 1);


        gridLayout_8->addWidget(groupBox_DownloadeFile, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_2 = new QGridLayout(groupBox_4);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pB_CreateMask = new QPushButton(groupBox_4);
        pB_CreateMask->setObjectName(QStringLiteral("pB_CreateMask"));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        pB_CreateMask->setFont(font);

        gridLayout_2->addWidget(pB_CreateMask, 4, 2, 1, 1);

        line_2 = new QFrame(groupBox_4);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_2, 0, 1, 6, 1);

        pB_filter = new QPushButton(groupBox_4);
        pB_filter->setObjectName(QStringLiteral("pB_filter"));
        pB_filter->setFont(font);

        gridLayout_2->addWidget(pB_filter, 0, 0, 1, 1);

        line = new QFrame(groupBox_4);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 0, 3, 6, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        checkBox_dilate = new QCheckBox(groupBox_4);
        checkBox_dilate->setObjectName(QStringLiteral("checkBox_dilate"));

        horizontalLayout_3->addWidget(checkBox_dilate);

        label = new QLabel(groupBox_4);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        label->setFont(font1);

        horizontalLayout_3->addWidget(label);

        spinBox_dilatePower = new QSpinBox(groupBox_4);
        spinBox_dilatePower->setObjectName(QStringLiteral("spinBox_dilatePower"));
        spinBox_dilatePower->setMaximum(200);
        spinBox_dilatePower->setValue(2);

        horizontalLayout_3->addWidget(spinBox_dilatePower);


        horizontalLayout_5->addLayout(horizontalLayout_3);


        gridLayout_2->addLayout(horizontalLayout_5, 0, 2, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        label_2->setFont(font2);

        horizontalLayout_4->addWidget(label_2);

        sB_inpaintRadius = new QSpinBox(groupBox_4);
        sB_inpaintRadius->setObjectName(QStringLiteral("sB_inpaintRadius"));
        sB_inpaintRadius->setValue(3);

        horizontalLayout_4->addWidget(sB_inpaintRadius);


        gridLayout_2->addLayout(horizontalLayout_4, 0, 4, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font2);

        horizontalLayout_2->addWidget(label_6);

        sB_treshold = new QSpinBox(groupBox_4);
        sB_treshold->setObjectName(QStringLiteral("sB_treshold"));
        sB_treshold->setMaximum(255);

        horizontalLayout_2->addWidget(sB_treshold);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 2, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        lbl_noiseArea = new QLabel(groupBox_4);
        lbl_noiseArea->setObjectName(QStringLiteral("lbl_noiseArea"));

        horizontalLayout_7->addWidget(lbl_noiseArea);

        sB_noiseArea = new QSpinBox(groupBox_4);
        sB_noiseArea->setObjectName(QStringLiteral("sB_noiseArea"));
        sB_noiseArea->setMaximum(10000);

        horizontalLayout_7->addWidget(sB_noiseArea);


        gridLayout_2->addLayout(horizontalLayout_7, 3, 2, 1, 1);

        pB_paint = new QPushButton(groupBox_4);
        pB_paint->setObjectName(QStringLiteral("pB_paint"));
        pB_paint->setFont(font);

        gridLayout_2->addWidget(pB_paint, 1, 4, 1, 1);

        line_3 = new QFrame(groupBox_4);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_3, 2, 4, 1, 1);

        pB_myPaint = new QPushButton(groupBox_4);
        pB_myPaint->setObjectName(QStringLiteral("pB_myPaint"));

        gridLayout_2->addWidget(pB_myPaint, 3, 4, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        lbl_hairWidth = new QLabel(groupBox_4);
        lbl_hairWidth->setObjectName(QStringLiteral("lbl_hairWidth"));

        horizontalLayout_6->addWidget(lbl_hairWidth);

        sB_hairWidth = new QSpinBox(groupBox_4);
        sB_hairWidth->setObjectName(QStringLiteral("sB_hairWidth"));

        horizontalLayout_6->addWidget(sB_hairWidth);


        gridLayout_2->addLayout(horizontalLayout_6, 4, 4, 1, 1);


        gridLayout_8->addWidget(groupBox_4, 1, 0, 2, 1);

        HaircutMainWidj->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(HaircutMainWidj);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 545, 20));
        HaircutMainWidj->setMenuBar(menuBar);
        mainToolBar = new QToolBar(HaircutMainWidj);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        HaircutMainWidj->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(HaircutMainWidj);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        HaircutMainWidj->setStatusBar(statusBar);

        retranslateUi(HaircutMainWidj);

        QMetaObject::connectSlotsByName(HaircutMainWidj);
    } // setupUi

    void retranslateUi(QMainWindow *HaircutMainWidj)
    {
        HaircutMainWidj->setWindowTitle(QApplication::translate("HaircutMainWidj", "HaircutMainWidj", Q_NULLPTR));
        groupBox_DownloadeFile->setTitle(QApplication::translate("HaircutMainWidj", "\320\227\320\260\320\263\321\200\321\203\320\267\320\272\320\260 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217", Q_NULLPTR));
        pB_DownloadFIle->setText(QApplication::translate("HaircutMainWidj", "...", Q_NULLPTR));
        rB_gray->setText(QApplication::translate("HaircutMainWidj", "GRAY", Q_NULLPTR));
        rB_red->setText(QApplication::translate("HaircutMainWidj", "Red", Q_NULLPTR));
        rB_hue->setText(QApplication::translate("HaircutMainWidj", "Hue", Q_NULLPTR));
        rB_green->setText(QApplication::translate("HaircutMainWidj", "Green", Q_NULLPTR));
        rB_saturation->setText(QApplication::translate("HaircutMainWidj", "Saturation", Q_NULLPTR));
        rB_blue->setText(QApplication::translate("HaircutMainWidj", "Blue", Q_NULLPTR));
        rB_value->setText(QApplication::translate("HaircutMainWidj", "Value", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("HaircutMainWidj", "FILTERING and  PAINT", Q_NULLPTR));
        pB_CreateMask->setText(QApplication::translate("HaircutMainWidj", "EDIT_MASK", Q_NULLPTR));
        pB_filter->setText(QApplication::translate("HaircutMainWidj", "FILTER", Q_NULLPTR));
        checkBox_dilate->setText(QApplication::translate("HaircutMainWidj", "DILATE", Q_NULLPTR));
        label->setText(QApplication::translate("HaircutMainWidj", "Power: ", Q_NULLPTR));
        label_2->setText(QApplication::translate("HaircutMainWidj", "Radius: ", Q_NULLPTR));
        label_6->setText(QApplication::translate("HaircutMainWidj", "Treshold: ", Q_NULLPTR));
        lbl_noiseArea->setText(QApplication::translate("HaircutMainWidj", "NOISE AREA: ", Q_NULLPTR));
        pB_paint->setText(QApplication::translate("HaircutMainWidj", "PAINT (INPAINT OPEN CV)", Q_NULLPTR));
        pB_myPaint->setText(QApplication::translate("HaircutMainWidj", "PAINT (MY METHOD)", Q_NULLPTR));
        lbl_hairWidth->setText(QApplication::translate("HaircutMainWidj", "HAIR_WIDTH: ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HaircutMainWidj: public Ui_HaircutMainWidj {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HAIRCUTMAINWIDJ_H
