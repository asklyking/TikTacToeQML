#include "LanguageController.h"

LanguageController::LanguageController(QGuiApplication *app, QObject *parent) : QObject(parent),
    m_app(app) {

}

QString LanguageController::emptyString() const {
    return "";
}

void LanguageController::clickChangeLanguage() {
    emit isLanguageChanged();
}
