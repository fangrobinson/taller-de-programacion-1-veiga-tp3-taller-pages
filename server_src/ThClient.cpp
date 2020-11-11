/*
#include "ThClient.h"
#include <atomic>


ThClient::ThClient() :keepTalking(true),
                        isRunning(true) {}


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

*/