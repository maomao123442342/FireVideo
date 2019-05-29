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
	void mouseDoubleClickEvent(QMouseEvent *event); //��Ļ˫���¼�
private:
	QMediaPlayer* FsPlayer; //ȫ��������
	MyVideoWidget* FsVideoWidget; //ȫ������
	FireSlider* FsPlaySlider; //ȫ��������
	QLabel* FsPlaySchedule;
	QLabel* FsPlaySumSchedule;
	FireVideo* FV; //������
};








#endif