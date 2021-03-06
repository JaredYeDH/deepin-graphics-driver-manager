
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "graphicsdeviceinfo.h"
#include "resolutions/resolutions.h"

#include <QVBoxLayout>

#include <DMainWindow>
#include <DWaterProgress>

DWIDGET_USE_NAMESPACE

class QPushButton;
class QLabel;
class MainWindow : public DMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void keyPressEvent(QKeyEvent *e);
    void noResolutions();

private Q_SLOTS:
    void loadResolutions();
    void onResolutionSelected();
    void onToggleBtnClicked();
    void onRebootBtnClicked();
    void onPolicyKitPassed();
    void onPrepareFinished(const int exitCode);

private:
    int m_usedIndex;
    int m_selectedIndex;
    bool m_started;
    GraphicsDeviceInfo m_devInfo;
    Resolutions m_resolutions;

    QVBoxLayout *m_resolutionsLayout;
    QLabel *m_topTips;
    QLabel *m_vendorIcon;
    QLabel *m_vendorName;
    QLabel *m_tipsIcon;
    QLabel *m_botTips;
    QWidget *m_resolutionsWidget;
    DWaterProgress *m_progress;
    QPushButton *m_toggleButton;
    QPushButton *m_okButton;
    QPushButton *m_rebootButton;
};

#endif
