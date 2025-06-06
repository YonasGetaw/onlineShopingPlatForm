QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# Enable PostgreSQL plugin


# You can make your code fail to compile if it uses deprecated APIs.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

  SOURCES += \
       main.cpp \
       database.cpp \
       login_controller.cpp \
       admin_controller.cpp \
       driver_controller.cpp \
       police_controller.cpp \
       session_manager.cpp \
       helpers.cpp

   HEADERS += \
       database.h \
       login_controller.h \
       admin_controller.h \
       driver_controller.h \
       police_controller.h \
       session_manager.h \
       helpers.h \
       admin.h \
       driver.h \
       traffic_police.h

   FORMS += \
       login.ui \
       admin_dashboard.ui \
       driver_dashboard.ui \
       police_dashboard.ui
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
