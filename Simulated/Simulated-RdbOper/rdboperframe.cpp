
#include <QtWidgets/QtWidgets>

#include "addRecordDialog.h"
#include "deleteRecordDialog.h"
#include "efficencyAnalyse.h"
#include "randomInsertDialog.h"
#include "rdboperframe.h"
#include "rdbTableFactory.h"
#include "selectCompleteDataDialog.h"
#include "selectDefaultDataDialog.h"
#include "selectEquipTreeDialog.h"
#include "selectSpecficDataDialog.h"
#include "structInsertThread.h"
#include "updateRecordDialog.h"

RdbOperFrame::RdbOperFrame(QWidget *parent)
	: QMainWindow(parent), m_adapterIdentify("SimulatedRdbOpt")
{
	createWidget();
	createActions();
	createMenus();
	createToolBars();
	createStatusBar();

	initIcePtr();
	updateActions();
}

RdbOperFrame::~RdbOperFrame()
{

}

// 重新获取实时库操作代理
RdbRealData::RdbDataOptPrx RdbOperFrame::regetRdbDataOptPrx()
{
	m_rdbDataOptPrx = 0;

	try
	{
		QString proxy = QString("rdb-opt: tcp -h %1 -p %2").arg(m_configIceInfo.iceOffsideIp).
			arg(m_configIceInfo.iceOffsidePort);
		m_rdbDataOptPrx = RdbDataOptPrx::checkedCast(m_communicatorPtr->stringToProxy(proxy.toStdString()));
	}
	catch(const Ice::Exception& ex)
	{
		m_rdbDataOptPrx = 0;
	}
	return m_rdbDataOptPrx;
}

void RdbOperFrame::createWidget()
{
	listView = new QListView;
	QStringList tableNames = RdbTableFactory::getTableNames();
	QStringListModel* listModel = new QStringListModel(tableNames);
	listView->setModel(listModel);

	tableView = new QTableView;

	QHBoxLayout* layout = new QHBoxLayout;
	layout->addWidget(listView, 1);
	layout->addWidget(tableView, 4);
	
	QWidget* widget = new QWidget;
	widget->setLayout(layout);
	setCentralWidget(widget);

	setWindowTitle(QStringLiteral("实时库操作"));
	setWindowIcon(QIcon(":/icon.png"));
	resize(1000, 800);
}

void RdbOperFrame::createActions()
{
	quitAppAction = createActionImpl(QIcon(":/quit.png"), QStringLiteral("退出程序"), 
		QStringLiteral("退出程序"), SLOT(close()));

	configServerAction = createActionImpl(QIcon(":/configServer.png"), QStringLiteral("配置Ice服务"), 
			QStringLiteral("配置Ice服务"), SLOT(configServer()));
	startServerAction = createActionImpl(QIcon(":/startServer.png"), QStringLiteral("启动Ice服务"), 
		QStringLiteral("启动Ice服务"), SLOT(startServer()));
	stopServerAction = createActionImpl(QIcon(":/stopServer.png"), QStringLiteral("停止Ice服务"), 
		QStringLiteral("停止Ice服务"), SLOT(stopServer()));

	selectDefaultDataAction = createActionImpl(QIcon(":/select.png"), QStringLiteral("查询默认数据"), 
		QStringLiteral("查询默认数据"), SLOT(selectDefaultData())); 
	selectSpecficDataAction = createActionImpl(QIcon(":/select.png"), QStringLiteral("查询指定数据"), 
		QStringLiteral("查询指定数据"), SLOT(selectSpecficData())); 
	selectCompleteDataAction = createActionImpl(QIcon(":/select.png"), QStringLiteral("查询全部数据"), 
		QStringLiteral("查询全部数据"), SLOT(selectCompleteData())); 
	selectEquipTreeAction = createActionImpl(QIcon(":/select.png"), QStringLiteral("查询设备树"), 
		QStringLiteral("查询设备树"), SLOT(selectEquipmentTree())); 
	
	addRecordAction = createActionImpl(QIcon(":/addRecord.png"), QStringLiteral("插入记录"), 
		QStringLiteral("插入记录"), SLOT(addRecord()));
	updateRecordAction = createActionImpl(QIcon(":/updateRecord.png"), QStringLiteral("更新记录"), 
		QStringLiteral("更新记录"), SLOT(updateRecord()));
	deleteRecordAction = createActionImpl(QIcon(":/deleteRecord.png"), QStringLiteral("删除记录"), 
		QStringLiteral("删除记录"), SLOT(deleteRecord()));

	randomInsertAction = createActionImpl(QIcon(":/random.png"), QStringLiteral("插入随机数据"), 
		QStringLiteral("插入随机数据"), SLOT(randomInsert()));
	structInsertAction = createActionImpl(QIcon(":/random.png"), QStringLiteral("插入结构化数据"), 
		QStringLiteral("插入结构化数据"), SLOT(structInsert()));

	analyseAction = createActionImpl(QIcon(":/analyse.png"), QStringLiteral("效率分析"), 
		QStringLiteral("效率分析"), SLOT(efficiencyAnalyse()));
}

QAction* RdbOperFrame::createActionImpl(const QIcon& icon, const QString& text, const QString& statusTip, const char* slot)
{
	QAction* action = new QAction(icon, text, this);
	action->setStatusTip(statusTip);
	connect(action, SIGNAL(triggered()), this, slot);

	return action;
}

void RdbOperFrame::createMenus()
{
	QMenu* fileMenu = menuBar()->addMenu(QStringLiteral("文件"));
	fileMenu->addAction(quitAppAction);

	QMenu* serverMenu = menuBar()->addMenu(QStringLiteral("Ice服务"));
	serverMenu->addAction(configServerAction);
	serverMenu->addAction(startServerAction);
	serverMenu->addAction(stopServerAction);

	QMenu* operMenu = menuBar()->addMenu(QStringLiteral("操作"));
	operMenu->addAction(selectDefaultDataAction);
	operMenu->addAction(selectSpecficDataAction);
	operMenu->addAction(selectCompleteDataAction);
	operMenu->addAction(selectEquipTreeAction);
	operMenu->addSeparator();
	operMenu->addAction(addRecordAction);
	operMenu->addAction(updateRecordAction);
	operMenu->addAction(deleteRecordAction);
	operMenu->addSeparator();
	operMenu->addAction(randomInsertAction);
	operMenu->addAction(structInsertAction);
	operMenu->addSeparator();
	operMenu->addAction(analyseAction);
}

void RdbOperFrame::createToolBars()
{
	QToolBar* fileToolBar = addToolBar(QStringLiteral("文件"));
	fileToolBar->addAction(quitAppAction);

	QToolBar* serverToolBar = addToolBar(QStringLiteral("Ice服务"));
	serverToolBar->addAction(configServerAction);
	serverToolBar->addAction(startServerAction);
	serverToolBar->addAction(stopServerAction);

	QToolBar* operToolBar = addToolBar(QStringLiteral("操作"));
	operToolBar->addAction(selectDefaultDataAction);
	operToolBar->addAction(selectSpecficDataAction);
	operToolBar->addAction(selectCompleteDataAction);
	operToolBar->addAction(selectEquipTreeAction);
	operToolBar->addSeparator();
	operToolBar->addAction(addRecordAction);
	operToolBar->addAction(updateRecordAction);
	operToolBar->addAction(deleteRecordAction);
	operToolBar->addSeparator();
	operToolBar->addAction(randomInsertAction);
	operToolBar->addAction(structInsertAction);
	operToolBar->addSeparator();
	operToolBar->addAction(analyseAction);
}

void RdbOperFrame::createStatusBar()
{
	statusBar()->showMessage(QStringLiteral("准备就绪"));
}

void RdbOperFrame::initIcePtr()
{
	m_communicatorPtr = 0;
	m_objectAdapterPtr = 0;
	m_rdbDataOptPrx = 0;
}

bool RdbOperFrame::getRdbDataOptPrx()
{
	if (m_rdbDataOptPrx)
	{
		return true;
	}

	try
	{
		QString proxy = QString("rdb-opt: tcp -h %1 -p %2").arg(m_configIceInfo.iceOffsideIp).
				arg(m_configIceInfo.iceOffsidePort);
		m_rdbDataOptPrx = RdbDataOptPrx::checkedCast(
			m_communicatorPtr->stringToProxy(proxy.toStdString())->ice_timeout(5000)
			);
		
		return true;
	}
	catch(const Ice::ConnectTimeoutException& ex)
	{
		QMessageBox::warning(this, QStringLiteral("获取实时库数据代理"), 
			QStringLiteral("获取代理失败: %1").arg(ex.what()));
		m_rdbDataOptPrx = 0;
		return false;
	}
	catch(const Ice::Exception& ex)
	{
		QMessageBox::warning(this, QStringLiteral("获取实时库数据代理"), 
			QStringLiteral("获取代理失败: %1").arg(ex.what()));
		m_rdbDataOptPrx = 0;
		return false;
	}
}

void RdbOperFrame::updateActions()
{
	bool enabled = m_communicatorPtr == NULL;

	startServerAction->setEnabled(enabled);
	stopServerAction->setEnabled(!enabled);
	addRecordAction->setEnabled(!enabled);
	deleteRecordAction->setEnabled(!enabled);
	updateRecordAction->setEnabled(!enabled);
	selectDefaultDataAction->setEnabled(!enabled);
	selectSpecficDataAction->setEnabled(!enabled);
	selectCompleteDataAction->setEnabled(!enabled);
	selectEquipTreeAction->setEnabled(!enabled);
	randomInsertAction->setEnabled(!enabled);
	structInsertAction->setEnabled(!enabled);
}

void RdbOperFrame::configServer()
{
	ConfigIceDialog configDialog(QIcon(":/configServer.png"));
	if (configDialog.exec() == QDialog::Accepted)
	{
		configDialog.saveConfigInfo();
		m_configIceInfo = configDialog.getConfigIceInfo();
	}
}

void RdbOperFrame::startServer()
{
	if (m_communicatorPtr)
	{
		return;
	}

	try
	{
		int argc = 0;
		Ice::InitializationData initData;
		initData.properties = Ice::createProperties();
		initData.properties->setProperty("Ice.MessageSizeMax", "10240");
		m_communicatorPtr = Ice::initialize(argc, 0, initData);
		QString endPoints = QString("tcp -h %1 -p %2").arg(m_configIceInfo.iceIp).arg(m_configIceInfo.icePort);
		m_objectAdapterPtr = m_communicatorPtr->createObjectAdapterWithEndpoints(m_adapterIdentify.toStdString(), 
			endPoints.toStdString());

		m_objectAdapterPtr->activate();

		updateStatusBar(QStringLiteral("Ice服务启动成功"));
	}
	catch(const Ice::Exception& ex)
	{
		initIcePtr();
		QMessageBox::warning(this, QStringLiteral("启动Ice服务"), 
			QStringLiteral("启动服务失败: %1").arg(ex.what()));
	}
	updateActions();
}

void RdbOperFrame::stopServer()
{
	if (m_communicatorPtr)
	{
		try
		{
			m_communicatorPtr->destroy();

			initIcePtr();
			updateStatusBar(QStringLiteral("Ice服务停止成功"));
		}
		catch(const Ice::Exception& ex)
		{
			initIcePtr();
			QMessageBox::warning(this, QStringLiteral("停止Ice服务"), 
				QStringLiteral("停止服务失败: %1").arg(ex.what()));
		}
	}
	updateActions();
}

void RdbOperFrame::selectDefaultData()
{
	if (!getRdbDataOptPrx())
	{
		return;
	}

	SelectDefaultDataDialog	selectDialog(m_rdbDataOptPrx);
	selectDialog.exec();
}

void RdbOperFrame::selectSpecficData()
{
	if (!getRdbDataOptPrx())
	{
		return;
	}

	SelectSpecficDataDialog	selectDialog(m_rdbDataOptPrx);
	selectDialog.exec();
}

void RdbOperFrame::selectCompleteData()
{
	if (!getRdbDataOptPrx())
	{
		return;
	}

	SelectCompleteDataDialog	selectDialog(m_rdbDataOptPrx);
	selectDialog.exec();
}

void RdbOperFrame::selectEquipmentTree()
{
	if (!getRdbDataOptPrx())
	{
		return;
	}

	SelectEquipTreeDialog	selectDialog(m_rdbDataOptPrx);
	selectDialog.exec();
}

void RdbOperFrame::addRecord()
{
	if (!getRdbDataOptPrx())
	{
		return;
	}

	AddRecordDialog	addDialog(m_rdbDataOptPrx);
	addDialog.exec();
}

void RdbOperFrame::updateRecord()
{
	if (!getRdbDataOptPrx())
	{
		return;
	}

	UpdateRecordDialog	updateDialog(m_rdbDataOptPrx);
	updateDialog.exec();
}

void RdbOperFrame::deleteRecord()
{
	if (!getRdbDataOptPrx())
	{
		return;
	}

	DeleteRecordDialog	deleteDialog(m_rdbDataOptPrx);
	deleteDialog.exec();
}

void RdbOperFrame::randomInsert()
{
	if (!getRdbDataOptPrx())
	{
		return;
	}

	RandomInsertDialog	randomInsertDialog(m_rdbDataOptPrx, this);
	randomInsertDialog.exec();
}

void RdbOperFrame::structInsert()
{
	if (!getRdbDataOptPrx())
	{
		return;
	}

	StructInsertThread* structInsertThread = new StructInsertThread(m_rdbDataOptPrx);
	connect(structInsertThread, SIGNAL(finished()), this, SLOT(structInsertFinished()));
	structInsertThread->start();
}

void RdbOperFrame::structInsertFinished()
{
	QMessageBox::information(this, QStringLiteral("结构化数据导入"), QStringLiteral("导入完成"));
}

void RdbOperFrame::efficiencyAnalyse()
{
	QString fileName = QFileDialog::getOpenFileName(this, QStringLiteral("打开文件"), ".");
	if (!fileName.isEmpty())
	{
		EfficiencyAnalyseThread* analysePtr = new EfficiencyAnalyseThread(fileName);
		analysePtr->start();
	}
}

void RdbOperFrame::updateTableView()
{

}

void RdbOperFrame::updateStatusBar( const QString& text, int timeout )
{
	statusBar()->showMessage(text, timeout);
}
