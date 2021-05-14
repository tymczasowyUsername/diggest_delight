#QT += gui
QT += network networkauth qml quick #widgets

CONFIG += c++14 console
#CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    src \
    src/models \
    src/screens \
    src/managers \
    src/network \
    src/datatypes

SOURCES += \
    src/main.cpp \
    src/network/DiscogsWrapper.cpp \
    src/models/ReleaseModel.cpp \
    src/network/ReplyParser.cpp \
    src/screens/ReleaseController.cpp \
    src/managers/ReleaseManager.cpp \
    src/network/UrlQueryCreator.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/datatypes/CollectionItem.h \
    src/datatypes/ReleaseRating.h \
    src/datatypes/RequestData.h \
    src/datatypes/WantlistItem.h \
    src/network/DiscogsWrapper.h \
    src/network/IDiscogsWrapper.h \
    src/models/ReleaseModel.h \
    src/network/ReplyParser.h \
    src/screens/ReleaseController.h \
    src/managers/ReleaseManager.h \
    src/network/UrlQueryCreator.h \
    src/datatypes/RequestData.h

RESOURCES += \
    src/qml.qrc
    img/images.qrc
    testdata/testdata.qrc
