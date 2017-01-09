#ifndef APP_SETTINGS_H
#define APP_SETTINGS_H

#include <QPushButton>
#include <QLabel>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QResizeEvent>

class AppSettings : public QWidget
{
    Q_OBJECT
public:
    explicit AppSettings(QWidget *parent = nullptr);
    bool            getRunAtStartState() const;
    void            setRunAtStartState(bool);
    void            setFindActiveServiceState(bool);
    void            setRestoreAtClose(bool);

signals:
    void            toBase();
    void            findActiveServiceStateChanged(bool);
    void            restoreAtCloseChanged(bool);

private:
    QLabel         *setLabel, *nameLabel;
    QPushButton    *baseButton;
    QHBoxLayout    *headLayout;
    QVBoxLayout    *appSetLayout;
    QCheckBox      *runAtStart, *findActiveService,
                   *restoreAtClose;
    QWidget        *headWdg, *appSettings;

    QVBoxLayout    *commonLayout;

public slots:

private slots:
    void            resizeEvent(QResizeEvent*);
};

#endif // APP_SETTINGS_H