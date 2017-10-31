#ifndef LANGUAGECONTROLLER_H
#define LANGUAGECONTROLLER_H

#include <QObject>
#include <QGuiApplication>
#include <QTranslator>

class LanguageController : public QObject
{
        Q_OBJECT
        Q_PROPERTY(QString emptyString READ emptyString NOTIFY isLanguageChanged)
    public:
        explicit LanguageController(QGuiApplication *app,QObject *parent = 0);
        QString emptyString() const;

    signals:
        void isLanguageChanged();

    public slots:
        void clickChangeLanguage();

    private:
        QGuiApplication *m_app;
        QTranslator *m_translator;
};

#endif // LANGUAGECONTROLLER_H
