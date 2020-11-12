#include "ThClient.h"
#include "Thread.h"
#include <atomic>

/*
ThClient::ThClient(Socket *peer) :keepTalking(true), isRunning(true) {
    this->peer = peer;
}*/

ThClient::ThClient(Socket *peer) {
    this->peer = peer;
    this->keepTalking = true;
    this->isRunning = true;
}

ThClient::~ThClient() {}


void ThClient::run() {
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
