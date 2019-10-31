#ifndef PARAMMANAGER_H
#define PARAMMANAGER_H
#include <QVariant>
#include <QSettings>
#include <QDebug>
#include "singleton.hpp"
namespace ZSS {
class ParamManager {
  public:
    ParamManager();
    ParamManager(const QString&);
    ~ParamManager();
    bool loadParam(QChar&, const QString&, QChar d = 0);
    bool loadParam(int&, const QString&, int d = 0);
    bool loadParam(double&, const QString&, double d = 0);
    bool loadParam(QString&, const QString&, QString d = "");
    bool loadParam(bool&, const QString&, bool d = false);
    bool changeParam(const QString&, const QVariant&);
    bool changeParam(const QString&, const QString&, const QVariant&);
    QStringList allKeys();
    QStringList allKeys(const QString&);
    QStringList allGroups();
    QVariant value(const QString&, const QVariant& defaultValue = QVariant());
    QVariant value(const QString&, const QString&, const QVariant& defaultValue = QVariant());
    void sync();
    void clear();
  protected:
    QSettings *settings;
};
class ParamManagerZSS: public ParamManager {
  public:
    ParamManagerZSS(): ParamManager("li.ini") {}
    ~ParamManagerZSS() {}
};
typedef Singleton<ParamManagerZSS> LParamManager;
}

#endif // PARAMMANAGER_H

// void QSettings::setPath(Format format, Scope scope, const QString &path)
// QSettings settings("./myapp.ini", QSettings::IniFormat);
