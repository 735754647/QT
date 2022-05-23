#pragma once
#pragma execution_character_set("utf-8")
#include <QtWidgets/QMainWindow>
#include "ui_QtandLeisai.h"
#include<QTimer>


class QtandLeisai : public QMainWindow
{
    Q_OBJECT

public:
    QtandLeisai(QWidget *parent = Q_NULLPTR);
	QTimer *_time;//¶¨Ê±Æ÷
	 void Move_AbsOrRel(ushort AbsAndRel);
	 void InitTableW();

private:
    Ui::QtandLeisaiClass ui;
signals:

private slots:
	void on_Bt_CardLint_clicked();
	void on_Bt_AxisEn_clicked();
	void on_Bt_AxisRestEn_clicked();
	void on_Bt_AxisJOGAdd_clicked();
	void on_Bt_AxisJOGSub_clicked();
	void on_Bt_AxisRunAbs_clicked();
	void on_Bt_AxisRunRel_clicked();
	void on_Bt_AxisStop_clicked();
	void on_Bt_AxisGoHome_clicked();
	void on_Bt_CleanAisxWarn_clicked();
	void on_Bt_CardClose_clicked();
	void on_Bt_RunTime_clicked();
	void on_Bt_SetOut_clicked();
	void on_Bt_RestOut_clicked();
	void on_chB_MoveOri_stateChanged(int arg1);
};
