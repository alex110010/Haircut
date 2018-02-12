 #include "haircutmainwidj.h"
#include "ui_haircutmainwidj.h"

RNG rng(12345);

bool selectObject = false;
Rect selection;
Point origin;
int trackObject = 0;
Mat original;

HaircutMainWidj::HaircutMainWidj(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HaircutMainWidj)
{
    ui->setupUi(this);
    connect(this, SIGNAL(IMAGE_WAS_DOWNLOADED()), this, SLOT(assignCallback()));
}

HaircutMainWidj::~HaircutMainWidj()
{
    delete ui;
}

void HaircutMainWidj::on_pB_DownloadFIle_clicked()
{
    QString imagePath = QFileDialog::getOpenFileName(this, "Выбор изображения", QApplication::applicationDirPath(), "Изображения (*.bmp *.jpg *.jpeg *.png)");
    qDebug() << "imagePath: " << imagePath;
    Mat bgrImage = imread(imagePath.toStdString().data(), IMREAD_COLOR); // BGR
    if (bgrImage.empty()){
        QMessageBox::information(0, "Справка", "Изображение не загружено! (Возможно путь к изображению содержит кириллицу)");
        return;
    }
    ui->lineEdit_ImagePath->setText(imagePath);
    this->bgrImage = bgrImage.clone();

    namedWindow("ORIGINAL", CV_WINDOW_NORMAL);
    imshow("ORIGINAL", bgrImage);

    // Разбиение на каналы B, G, R
    Mat BGRchannels[3];
    split(bgrImage, BGRchannels);

    B = BGRchannels[0].clone();
    G = BGRchannels[1].clone();
    R = BGRchannels[2].clone();

    // Перевод в HSV
    Mat hsvImage;
    cvtColor(bgrImage, hsvImage, CV_BGR2HSV);
    this->hsvImage = hsvImage.clone();

    // Разбиение на каналы HSV
    Mat HSVchannels[3];
    split(hsvImage, HSVchannels);

    H = HSVchannels[0];
    S = HSVchannels[1];
    V = HSVchannels[2];

    // Перевод в градации серого
    Mat grayImage;
    cvtColor(bgrImage, grayImage, CV_BGR2GRAY);
    this->grayImage = grayImage.clone();

    // Инициализация цветовой компоненты для дальнейшего анализа
    this->analyzeImage = grayImage;

    emit IMAGE_WAS_DOWNLOADED();
}

void HaircutMainWidj::on_rB_gray_clicked()
{
    ui->rB_red->setChecked(false);
    ui->rB_green->setChecked(false);
    ui->rB_blue->setChecked(false);
    ui->rB_hue->setChecked(false);
    ui->rB_saturation->setChecked(false);
    ui->rB_value->setChecked(false);

    if (grayImage.data){
        analyzeImage = grayImage.clone();
    }
}

void HaircutMainWidj::on_rB_red_clicked()
{
    ui->rB_gray->setChecked(false);
    ui->rB_green->setChecked(false);
    ui->rB_blue->setChecked(false);
    ui->rB_hue->setChecked(false);
    ui->rB_saturation->setChecked(false);
    ui->rB_value->setChecked(false);

    if (R.data){
        analyzeImage = R.clone();
    }
}

void HaircutMainWidj::on_rB_green_clicked()
{
    ui->rB_gray->setChecked(false);
    ui->rB_red->setChecked(false);
    ui->rB_blue->setChecked(false);
    ui->rB_hue->setChecked(false);
    ui->rB_saturation->setChecked(false);
    ui->rB_value->setChecked(false);

    if (G.data){
        analyzeImage = G.clone();
    }
}

void HaircutMainWidj::on_rB_blue_clicked()
{
    ui->rB_gray->setChecked(false);
    ui->rB_red->setChecked(false);
    ui->rB_green->setChecked(false);
    ui->rB_hue->setChecked(false);
    ui->rB_saturation->setChecked(false);
    ui->rB_value->setChecked(false);

    if (B.data){
        analyzeImage = B.clone();
    }
}

void HaircutMainWidj::on_rB_hue_clicked()
{
    ui->rB_gray->setChecked(false);
    ui->rB_red->setChecked(false);
    ui->rB_green->setChecked(false);
    ui->rB_blue->setChecked(false);
    ui->rB_saturation->setChecked(false);
    ui->rB_value->setChecked(false);

    if (H.data){
        analyzeImage = H.clone();
    }
}

void HaircutMainWidj::on_rB_saturation_clicked()
{
    ui->rB_gray->setChecked(false);
    ui->rB_red->setChecked(false);
    ui->rB_green->setChecked(false);
    ui->rB_blue->setChecked(false);
    ui->rB_hue->setChecked(false);
    ui->rB_value->setChecked(false);

    if (S.data){
        analyzeImage = S.clone();
    }
}

void HaircutMainWidj::on_rB_value_clicked()
{
    ui->rB_gray->setChecked(false);
    ui->rB_red->setChecked(false);
    ui->rB_green->setChecked(false);
    ui->rB_blue->setChecked(false);
    ui->rB_hue->setChecked(false);
    ui->rB_saturation->setChecked(false);

    if (V.data){
        analyzeImage = V.clone();
    }
}

void HaircutMainWidj::on_pB_paint_clicked()
{
    if (!mask.data){return;}

    Mat result;
    int radius = ui->sB_inpaintRadius->value();
    inpaint(bgrImage, mask, result, radius, INPAINT_NS);

    namedWindow("RESULT", CV_WINDOW_NORMAL);
    imshow("RESULT", result);
}

void HaircutMainWidj::on_pB_CreateMask_clicked()
{
    if (!f1_image.data || !f2_image.data){return;}

    // Sum
    Mat sum_f1_f2;
    addWeighted( f1_image, 1, f2_image, 1, 0, sum_f1_f2, -1 );
    qDebug() << "sum_f1_f2: max = " << cv::norm(sum_f1_f2, NORM_INF);

    // Save sum
    f12 = sum_f1_f2.clone();

    // Show sum
    namedWindow("FILTER RESULT", CV_WINDOW_NORMAL);
    imshow("FILTER RESULT", sum_f1_f2);

    // Binary
    Mat binary;
    int thresh = ui->sB_treshold->value();
    threshold( sum_f1_f2, binary, thresh, 255, THRESH_BINARY);

    // Dilate binary
    if (ui->checkBox_dilate->isChecked()){
        int power = ui->spinBox_dilatePower->value();
        int morph_type = MORPH_ELLIPSE;
        int morph_size = 2; // width = 2*n + 1
        Mat element = getStructuringElement( morph_type,
                                             Size( 2*morph_size + 1, 2*morph_size+1 ),
                                             Point( morph_size, morph_size ) );
        for (int i = 0; i < power; i++){
            dilate(binary, binary, element);
        }
    }

    // SAVE MASK
    this->mask = binary.clone();
    for (int r = 0; r < mask.rows; r++){
        for (int c = 0; c < mask.cols; c++){
            if (selection.x < c && c < selection.x + selection.width &&
                    r < selection.y + selection.height && selection.y < r){
                mask.at<uchar>(r, c) = 0;
            }
        }
    }

    // SOURCE + BINARY MASK
    Mat src_masked = bgrImage.clone();
    for (int r = 0; r < binary.rows; r++){
        for (int c = 0; c < binary.cols; c++){
            int color = static_cast<int>(binary.at<uchar>(r, c));
            if (color == 255){
                src_masked.at<Vec3b>(r, c) = Vec3b(0, color, 0); // green
            }
        }
    }

    // УБЕРЕМ ПЯТНО ИЗ-ПОД МАСКИ (ОТБОР ПО ПЛОЩАДИ)
    // -------------------------------------------------------------------------------------------------------------
    Mat removeNoiseImg(src_masked.rows + 2, src_masked.cols + 2, src_masked.type(), Scalar(255, 0, 0));
    for (int r = 0; r < src_masked.rows; r++){
        for (int c = 0; c < src_masked.cols; c++){
            removeNoiseImg.at<Vec3b>(r + 1, c + 1) = src_masked.at<Vec3b>(r, c);
        }
    }

    for (int row = 1; row < removeNoiseImg.rows - 1; row++){
        for (int col = 1; col < removeNoiseImg.cols - 1; col++){

            if (removeNoiseImg.at<Vec3b>(row, col) == Vec3b(0, 255, 0)){ // GREEN
                stack<Point> processedPts;
                processedPts.push(Point(col, row)); // положили первую точку объекта в стек
                removeNoiseImg.at<Vec3b>(row, col) = Vec3b(0, 0, 255); // окрасили в красный цвет

                vector<int> ptsX;
                vector<int> ptsY;
                ptsX.push_back(col);
                ptsY.push_back(row);

                while(!processedPts.empty()){

                    Point lastPt = processedPts.top();
                    processedPts.pop();
                    int c = lastPt.x;
                    int r = lastPt.y;

                    Mat neighborhood(removeNoiseImg, Rect(c - 1, r - 1, 3, 3));

                    for (int i = 0; i < neighborhood.rows; i++){
                        for (int j = 0; j < neighborhood.cols; j++){
                            if (neighborhood.at<Vec3b>(i, j) == Vec3b(0, 255, 0)){
                                processedPts.push(Point(c - 1 + j, r - 1 + i));
                                removeNoiseImg.at<Vec3b>(r - 1 + i, c - 1 + j) = Vec3b(0, 0, 255);

                                ptsX.push_back(c - 1 + j);
                                ptsY.push_back(r - 1 + i);
                            }
                        }
                    }
                }

                // конец обработки стека
                if (ptsX.size() < ui->sB_noiseArea->value()){
                    for (int i = 0; i < ptsX.size(); i++){
                        removeNoiseImg.at<Vec3b>(ptsY[i], ptsX[i]) = bgrImage.at<Vec3b>(ptsY[i] - 1, ptsX[i] - 1);
                    }
                }

                // очистка векторов
                ptsX.clear();
                ptsY.clear();
            }
            // конец if
        }
    }
    // -------------------------------------------------------------------------------------------------------------

    // Заменить красный маркер на зеленый
    Mat finalMask(removeNoiseImg, Rect(1, 1, removeNoiseImg.cols - 2, removeNoiseImg.rows - 2));
    for (int r = 0; r < finalMask.rows; r++){
        for (int c = 0; c< finalMask.cols; c++){
            if (finalMask.at<Vec3b>(r, c) == Vec3b(0, 0, 255)){
                finalMask.at<Vec3b>(r, c) = Vec3b(0, 255, 0);
            }
        }
    }
    final_mask = finalMask.clone();
    namedWindow("FINAL_MASK", CV_WINDOW_NORMAL);
    imshow("FINAL_MASK", finalMask);
}

void HaircutMainWidj::assignCallback(){
    original = bgrImage.clone();
    namedWindow("SELECT ROI EXCLUDED FROM THE ANALYSIS", CV_WINDOW_NORMAL);
    setMouseCallback("SELECT ROI EXCLUDED FROM THE ANALYSIS", onMouse, 0);
    imshow("SELECT ROI EXCLUDED FROM THE ANALYSIS", original);
}

// обработчик событий от мышки
void HaircutMainWidj::onMouse( int event, int x, int y, int, void* )
{
    if (!original.data){
        return;
    }

    Mat img = original.clone();

    if( selectObject )
    {
        selection.x = MIN(x, origin.x);
        selection.y = MIN(y, origin.y);
        selection.width = std::abs(x - origin.x);
        selection.height = std::abs(y - origin.y);

        selection &= Rect(0, 0, img.cols, img.rows);
    }

    switch( event )
    {
    case CV_EVENT_LBUTTONDOWN:
        origin = Point(x,y);
        selection = Rect(x,y,0,0);
        selectObject = true;
        break;
    case CV_EVENT_LBUTTONUP:
        selectObject = false;
        if( selection.width > 0 && selection.height > 0 ){
            trackObject = -1;
        }
        printf("%d %d %d %d\n", selection.x, selection.y, selection.width, selection.height);
        break;
    case CV_EVENT_MOUSEMOVE:
        break;
    }

    if( selectObject){
        Mat roi(img, selection);
        bitwise_not(roi, roi);
        imshow( "SELECT ROI EXCLUDED FROM THE ANALYSIS", img );
    }
}

void HaircutMainWidj::on_pB_filter_clicked()
{
    if (!analyzeImage.data){
        return;
    }

    Mat gray = analyzeImage.clone();

    // Median Blur
    int width_kernel = 15;
    medianBlur(gray, gray, width_kernel);

    // Initialize kernel
    Mat kernel1(1, 19, CV_32F);
    kernel1.at<float>(0) = 6;
    kernel1.at<float>(1) = 4;
    kernel1.at<float>(2) = 2;
    kernel1.at<float>(3) = 1;

    kernel1.at<float>(4) = 0;
    kernel1.at<float>(5) = -1;
    kernel1.at<float>(6) = -2;
    kernel1.at<float>(7) = -3;

    kernel1.at<float>(8) = -4;
    kernel1.at<float>(9) = -7;
    kernel1.at<float>(10) = -4;
    kernel1.at<float>(11) = -3;

    kernel1.at<float>(12) = -2;
    kernel1.at<float>(13) = -1;
    kernel1.at<float>(14) = 0;
    kernel1.at<float>(15) = 1;

    kernel1.at<float>(16) = 2;
    kernel1.at<float>(17) = 4;
    kernel1.at<float>(18) = 6;

    // Apply filter
    Mat result1;
    filter2D(gray, result1, -1, kernel1, Point(-1,-1)); // result в тонах серого

    // Save image after filtering
    f1_image = result1.clone();
    emit IMAGE_WAS_FILTERED_1(result1.clone());

    // Initialize kernel
    Mat kernel2(19, 1, CV_32F);
    kernel2.at<float>(0) = 6;
    kernel2.at<float>(1) = 4;
    kernel2.at<float>(2) = 2;
    kernel2.at<float>(3) = 1;

    kernel2.at<float>(4) = 0;
    kernel2.at<float>(5) = -1;
    kernel2.at<float>(6) = -2;
    kernel2.at<float>(7) = -3;

    kernel2.at<float>(8) = -4;
    kernel2.at<float>(9) = -7;
    kernel2.at<float>(10) = -4;
    kernel2.at<float>(11) = -3;

    kernel2.at<float>(12) = -2;
    kernel2.at<float>(13) = -1;
    kernel2.at<float>(14) = 0;
    kernel2.at<float>(15) = 1;

    kernel2.at<float>(16) = 2;
    kernel2.at<float>(17) = 4;
    kernel2.at<float>(18) = 6;

    // Apply filter
    Mat result2;
    filter2D(gray, result2, -1, kernel2, Point(-1,-1));

    // Save image after filtering
    f2_image = result2.clone();
    emit IMAGE_WAS_FILTERED_2(result2.clone());
}

void HaircutMainWidj::on_pB_myPaint_clicked()
{
    // INPAINT
    int HAIR_WIDTH = ui->sB_hairWidth->value();
    Mat BGR = bgrImage.clone();
    Mat finalMask = final_mask.clone();

    for (int r = 0; r < finalMask.rows; r++){
        int c = 0;
        while (c < finalMask.cols){
            if (finalMask.at<Vec3b>(r, c) == Vec3b(0, 255, 0)){
                int i = 0;
                while (1){
                    if (c + i < finalMask.cols){
                        if (finalMask.at<Vec3b>(r, c + i) == Vec3b(0, 255, 0)){
                            i++;
                        }
                        else { break; }
                    }
                    else { break; }
                }

                int left = c;
                int right = c + i - 1;

                if (left - 1 > 0 && right + 1 < BGR.cols && right - left < HAIR_WIDTH){

                    // gradient
                    Vec3b grad1 = bgrImage.at<Vec3b>(r, left - 1);
                    Vec3b grad2 = bgrImage.at<Vec3b>(r, right + 1);

                    Vec3b delta_grad = (grad2 - grad1)/(i + 1);
                    int j = left;
                    while (j < right + 1){
                        /*
                        if (selection.x < j && j < selection.x + selection.width &&
                                r < selection.y + selection.height && selection.y < r ){
                            break;
                        }
                        */
                        grad1 += delta_grad;
                        BGR.at<Vec3b>(r, j) = grad1;
                        finalMask.at<Vec3b>(r, j) = Vec3b(0 ,0, 255); // RED
                        j++;
                    }

                }

                /*
                int leftIn = c; int rightIn = c + (i - 1);
                int leftOut = c - 1; int rightOut = c + i;

                if (i < HAIR_WIDTH){
                    while (leftIn < rightIn){

                        if (leftOut >= 0){
                            BGR.at<Vec3b>(r, leftIn) = bgrImage.at<Vec3b>(r, leftOut);
                            finalMask.at<Vec3b>(r, leftIn) = Vec3b(255, 0, 0);
                            leftIn++;
                            leftOut--;
                        }

                        if (rightOut < finalMask.cols){
                            BGR.at<Vec3b>(r, rightIn) = bgrImage.at<Vec3b>(r, rightOut);
                            finalMask.at<Vec3b>(r, rightIn) = Vec3b(255, 0, 0);
                            rightIn--;
                            rightOut++;
                        }

                    }

                    if (leftIn == rightIn){
                        if (leftOut >= 0){
                            BGR.at<Vec3b>(r, leftIn) = bgrImage.at<Vec3b>(r, leftOut);
                            finalMask.at<Vec3b>(r, leftIn) = Vec3b(255, 0, 0);
                        }
                        else {
                            BGR.at<Vec3b>(r, leftIn) = bgrImage.at<Vec3b>(r, rightOut);
                            finalMask.at<Vec3b>(r, leftIn) = Vec3b(255, 0, 0);
                        }
                    }
                }
                */

                c += i;
            }
            else{
                c++;
            }
        }
    }

    // INPAINT
    for (int c = 0; c < finalMask.cols; c++){
        int r = 0;
        while (r < finalMask.rows){
            if (finalMask.at<Vec3b>(r, c) == Vec3b(0, 255, 0)){
                int i = 0;
                while (1){
                    if (r + i < finalMask.rows){
                        if (finalMask.at<Vec3b>(r + i, c) == Vec3b(0, 255, 0)){
                            i++;
                        }
                        else { break; }
                    }
                    else { break; }
                }

                int left = r;
                int right = r + i - 1;

                if (left - 1 > 0 && right + 1 < BGR.rows){
                    Vec3b grad1 = bgrImage.at<Vec3b>(left - 1, c);
                    Vec3b grad2 = bgrImage.at<Vec3b>(right + 1, c);

                    Vec3b delta_grad = (grad2 - grad1)/(i + 1);
                    int j = left;
                    while (j < right + 1){
                        /*
                        if (selection.x < c && c < selection.x + selection.width &&
                                j < selection.y + selection.height && selection.y < j ){
                            break;
                        }
                        */
                        grad1 += delta_grad;
                        BGR.at<Vec3b>(j, c) = grad1;
                        j++;
                    }
                }

                /*
                int topIn = r; int bottomIn = r + (i - 1);
                int topOut = r - 1; int bottomOut = r + i;

                while (topIn < bottomIn){

                    if (topOut >= 0){
                        BGR.at<Vec3b>(topIn, c) = BGR.at<Vec3b>(topOut, c);
                        topIn++;
                        topOut--;
                    }

                    if (bottomOut < finalMask.rows){
                        BGR.at<Vec3b>(bottomIn, c) = BGR.at<Vec3b>(bottomOut, c);
                        bottomIn--;
                        topOut++;
                    }

                }

                if (topIn == bottomIn){
                    if (topOut >= 0){
                        BGR.at<Vec3b>(topIn, c) = BGR.at<Vec3b>(topOut, c);
                    }
                    else {
                        BGR.at<Vec3b>(topIn, c) = BGR.at<Vec3b>(bottomOut, c);
                    }
                }
                */

                r += i;
            }
            else{
                r++;
            }
        }
    }

    // SHOW INPAINT
    namedWindow("INPAINT", CV_WINDOW_NORMAL);
    imshow("INPAINT", BGR);
}
