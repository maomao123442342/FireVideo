#ifndef _FIREBUTTON_H_
#define _FIREBUTTON_H_
#include <QtGui>
#include <QtWidgets>
#include <qwidgetresizehandler_p.h>

class FireButton :public QPushButton
{
	Q_OBJECT
public:
	FireButton(QWidget *parent = Q_NULLPTR);
	~FireButton();
	void Input_Button_Icon(QIcon& N, QIcon& F = QIcon(), QIcon& P = QIcon()); //设置按键三种状态图标,FocusIcon/PressIcon默认情况下均为正常图标
	void Set_HintInfo(QLabel* info); //设置进入按键的提示信息,默认
protected:
	void enterEvent(QEvent *event); //鼠标进入事件
	void leaveEvent(QEvent *event);//鼠标离开事件
	//void mousePressEvent(QMouseEvent* event); //屏幕单击事件
	void mouseMoveEvent(QMouseEvent *e); //鼠标移动
	//void mouseDoubleClickEvent(QMouseEvent *event); //屏幕双击事件
private:
	QIcon NormalIcon;
	QIcon FocusIcon;
	QIcon PressIcon;
	QLabel* hintOpenfile;
	QPoint CursorPos;//光标位置点
	QPoint ButtonPos;//按键在主界面中的位置
	qint16 Text_Size; //提示文字的大小
};

#endif