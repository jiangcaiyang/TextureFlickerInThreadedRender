#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSurfaceFormat>
#include "TexturedCubeView.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<TexturedCubeView>( "QtProblem", 1, 0, "TexturedCubeView" );
    qmlRegisterType<TexturedCube>( "QtProblem", 1, 0, "TexturedCube" );

    // 注册一些类
    QSurfaceFormat defaultFormat;
    defaultFormat.setSamples( 4 );
    QSurfaceFormat::setDefaultFormat( defaultFormat );

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
