#ifndef TEXTUREDCUBEVIEW_H
#define TEXTUREDCUBEVIEW_H

#include <QVector3D>
#include <QMatrix4x4>
#include <QQuickItem>

class TexturedCubeView;
class TexturedCubeRenderer;
class TexturedCube: public QObject
{
    Q_OBJECT
    Q_PROPERTY( qreal length READ length WRITE setLength NOTIFY lengthChanged )
    Q_PROPERTY( QUrl source READ source WRITE setSource NOTIFY sourceChanged )
    Q_PROPERTY( QVector3D translate READ translate WRITE setTranslate NOTIFY translateChanged )
public:
    TexturedCube( QObject* parent = Q_NULLPTR );
    void initialize( void );
    void render( void );
    void sync( void );
    void release( void );
    void setView( TexturedCubeView* view ) { m_view = view; }

    qreal length( void ) { return m_length; }
    void setLength( qreal length );

    QUrl source( void ) { return m_source; }
    void setSource( const QUrl& source );

    QVector3D translate( void ) { return m_translate; }
    void setTranslate( const QVector3D& translate );

    friend class TexturedCubeRenderer;
signals:
    void lengthChanged( void );
    void sourceChanged( void );
    void translateChanged( void );
protected:
    void updateWindow( void );

    qreal               m_length;
    bool                m_lengthDirty;

    QUrl                m_source;
    bool                m_sourceDirty;

    // 模型矩阵
    QVector3D           m_translate;
    //QMatrix4x4          m_modelMatrix;

    TexturedCubeRenderer* m_renderer;
    TexturedCubeView*   m_view;
};

class TexturedCubeView : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY( QVector3D position READ position WRITE setPosition NOTIFY positionChanged )
    Q_PROPERTY( QVector3D lookAt READ lookAt WRITE setLookAt NOTIFY lookAtChanged )
    Q_PROPERTY( QVector3D up READ up WRITE setUp NOTIFY upChanged )
    Q_PROPERTY( qreal fieldOfView READ fieldOfView WRITE setFieldOfView NOTIFY fieldOfViewChanged )
    Q_PROPERTY( qreal aspectRatio READ aspectRatio WRITE setAspectRatio NOTIFY aspectRatioChanged )
    Q_PROPERTY( qreal nearPlane READ nearPlane WRITE setNearPlane NOTIFY nearPlaneChanged )
    Q_PROPERTY( qreal farPlane READ farPlane WRITE setFarPlane NOTIFY farPlaneChanged )
    Q_PROPERTY( QQmlListProperty<QObject> data READ data )
    Q_CLASSINFO( "DefaultProperty", "data" )
public:
    TexturedCubeView( QQuickItem* parent = Q_NULLPTR );
    ~TexturedCubeView( void );

    QVector3D position( void ) { return m_position; }
    void setPosition( const QVector3D& position );

    QVector3D lookAt( void ) { return m_lookAt; }
    void setLookAt( const QVector3D& lookAt );

    QVector3D up( void ) { return m_up; }
    void setUp( const QVector3D& up );

    qreal fieldOfView( void ) { return m_fieldOfView; }
    void setFieldOfView( qreal fieldOfView );

    qreal aspectRatio( void ) { return m_aspectRatio; }
    void setAspectRatio( qreal aspectRatio );

    qreal nearPlane( void ) { return m_nearPlane; }
    void setNearPlane( qreal nearPlane );

    qreal farPlane( void ) { return m_farPlane; }
    void setFarPlane( qreal farPlane );

    QMatrix4x4& viewMatrix( void ) { return m_viewMatrix; }
    QMatrix4x4& projectionMatrix( void ) { return m_projectionMatrix; }

    QQmlListProperty<QObject> data( void );
    void initialize( void );
    friend class TexturedCubeRenderer;
signals:
    void positionChanged( void );
    void lookAtChanged( void );
    void upChanged( void );
    void aspectRatioChanged( void );
    void fieldOfViewChanged( void );
    void nearPlaneChanged( void );
    void farPlaneChanged( void );
    void propertyChanged( void );
protected slots:
    void onWindowChanged( QQuickWindow* win );
    void render( void );
    void sync( void );
    void cleanup( void );

protected:
    void updateWindow( void );
    void calculateViewMatrix( void );
    void calculateProjectionMatrix( void );
    static void qobjectListAppend( QQmlListProperty<QObject>* prop, QObject* object );

    QObjectList                 m_data;

    QVector3D                   m_position, m_lookAt, m_up;
    qreal                       m_aspectRatio, m_fieldOfView;
    qreal                       m_nearPlane, m_farPlane;

    // 视角矩阵以及投影矩阵
    QMatrix4x4                  m_viewMatrix;
    QMatrix4x4                  m_projectionMatrix;

    bool                        m_initialized;
};

#endif // TEXTUREDCUBEVIEW_H
