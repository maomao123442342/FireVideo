#ifndef _FULLSCREEN_H_
#define _FULLSCREEN_H_
#include <QtGui>
#include <QtWidgets/qwidget.h>
#include <QMediaPlaylist>
#include <MyVideoWidget.h> 
#include "FireButton.h"
#include "FireSlider.h"
#include "firevideo.h"

class FireVideo;
class FullScreenWidget :public QVideoWidget
{
	Q_OBJECT
public:
	explicit FullScreenWidget(QWidget* parent = 0);
	~FullScreenWidget();
	void Set_ParentForm(FireVideo* parent);
private slots:
	void IsHiddedChangedSlot(bool ishidded);
	//signals:
	//	void IsHiddedChanged(bool hide);
protected:
	void mouseDoubleClickEvent(QMouseEvent *event); //屏幕双击事件
private:
	QMediaPlayer* FsPlayer; //全屏播放器
	MyVideoWidget* FsVideoWidget; //全屏窗口
	FireSlider* FsPlaySlider; //全屏进度条
	QLabel* FsPlaySchedule;
	QLabel* FsPlaySumSchedule;
	FireVideo* FV; //主界面
};








#endif