import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import qyvlik.http.server 0.1

ApplicationWindow {
    visible: true
    width: 360
    height: 640
    title: qsTr("Hello World")

    HttpServer {
        id: httpServer
        onConnection: {
            console.log(serverRequest);
            console.log(serverResponse);

            console.log(serverRequest.url());
            serverRequest.collectData(1024);

            serverRequest.end.connect(function(){
                console.log(serverRequest.collectedData());
                serverResponse.setStatusCode(200);
                var message = "From QML";
                serverResponse.addHeader("content-length", message.length);
                serverResponse.end(message);
            })
        }
    }

    function handle(serverReques, serverResponse) {

    }

    Item {
        anchors.fill: parent
        Button {
            anchors.centerIn: parent
            onClicked: {
                httpServer.listen("localhost", 10022);
            }
        }
    }

}
