#ifndef WIDGET_H
#define WIDGET_H

#include <QDialog>


namespace Ui { class camera; }


class QCamera ;
class QCameraViewfinder ;
class QCameraImageCapture ;
class QVBoxLayout ;
class QMenu ;
class QAction ;





class camera : public QWidget
{
   Q_OBJECT

public:
   explicit camera(QWidget *parent = nullptr);
   ~camera();

private:
   Ui::camera *ui;
   QCamera *mCamera ;
   QCameraViewfinder *mCameraViewfinder ;
   QCameraImageCapture *mCameraImageCapture ;
   QVBoxLayout  *mLayout ;
   QMenu *mOptionMenu ;
   QAction *mAllumerAction ;
   QAction *mEteindreAction ;
   QAction *mCaturerAction ;





};
#endif // WIDGET_H

