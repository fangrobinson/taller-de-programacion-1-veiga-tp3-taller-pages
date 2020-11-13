#include "ThClient.h"
#include "Thread.h"
#include <atomic>
#include "../common_src/SocketException.h"

ThClient::ThClient(Socket *peer) {
    this->peer = peer;
    this->keepTalking = true;
    this->isRunning = true;
    this->start();
}

ThClient::~ThClient() {}


void ThClient::run() {
    printf("Im talkin hehe");
    while (this->keepTalking) {
        try {

        } catch (SocketException) {
            continue;
        }
        //
        //...
        //peer.send()
        //...
        //peer.rcv()
        //...
    }
    this->isRunning = false;
    return;
    while (this->keepTalking) {
        //...
        //peer.send()
        //...
        //peer.rcv()
        //...
    }
    this->isRunning = false;
}

void ThClient::stop() {
    keepTalking = false;
    //peer.shutDown();
    //peer.close();
}

bool ThClient::isDead() {
    return not this->isRunning;
}
