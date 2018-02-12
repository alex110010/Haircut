#ifndef HAIRCUTMAINWIDJ_H
#define HAIRCUTMAINWIDJ_H

#include <QMainWindow>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/photo/photo.hpp>
#include <opencv2/legacy/legacy.hpp>

#include <QFileDialog>
#include <QMessageBox>
#include <QLabel>
#include <QPixmap>
#include <QDebug>
#include <QFile>
#include <QTextStream>

#include <stack>
#include <QStack>

using namespace std;
using namespace cv;

namespace Ui {
class HaircutMainWidj;
}

class HaircutMainWidj : public QMainWindow
{
    Q_OBJECT

public:
    explicit HaircutMainWidj(QWidget *parent = 0);
    ~HaircutMainWidj();

    // Mouse callback
    static void onMouse( int event, int x, int y, int, void* );

private slots:
    void on_pB_DownloadFIle_clicked();

    void on_rB_gray_clicked();

    void on_rB_red_clicked();

    void on_rB_green_clicked();

    void on_rB_blue_clicked();

    void on_rB_hue_clicked();

    void on_rB_saturation_clicked();

    void on_rB_value_clicked();

    void on_pB_paint_clicked();

    void on_pB_CreateMask_clicked();

    void assignCallback();

    void on_pB_filter_clicked();

    void on_pB_myPaint_clicked();

private:
    Ui::HaircutMainWidj *ui;
    Mat bgrImage; Mat R; Mat G; Mat B;
    Mat hsvImage; Mat H; Mat S; Mat V;
    Mat grayImage;

    Mat analyzeImage;

    Mat f1_image;
    Mat f2_image;
    Mat f12;
    Mat mask;
    Mat final_mask;
signals:
    void IMAGE_WAS_FILTERED_1(Mat f1_image);
    void IMAGE_WAS_FILTERED_2(Mat f2_image);
    void IMAGE_WAS_DOWNLOADED();
    // there was signal IMAGE_WAS_DOWNLOADED
};

#endif // HAIRCUTMAINWIDJ_H
