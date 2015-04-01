import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtProblem 1.0

Window
{
    visible: true
    width: 320
    height: 480

    TexturedCubeView
    {
        objectName: "view"
        anchors.fill: parent

        TexturedCube
        {
            objectName: "textureCube_1"
            source: "image/stone.jpg"
            length: 10
        }

        TexturedCube
        {
            objectName: "textureCube_2"
            source: "image/fruit.jpg"
            length: 3

            translate: Qt.vector3d( 0, 15, 0 )
        }

        readonly property int distance: 30
        position: Qt.vector3d( distance * Math.sin( angle ),
                              10, distance * Math.cos( angle ) )
        lookAt: Qt.vector3d( 0, 10, 0 )

        property real angle: 0.0

        NumberAnimation on angle
        {
            from: 0
            to: 2 * Math.PI
            duration: 20000
            loops: Animation.Infinite
            running: true
        }
    }

    Label
    {
        anchors.centerIn: parent
        horizontalAlignment: Text.AlignHCenter
        text: "This example shows\n my problem on flickering the screen."
        color: "white"
    }
}
