#include "FakeVectorRAM.hpp"

const VectorHandler & IVector::getHandler() {
    return _handler;
}

void IVector::setMark(bool mark) {
    _mark = mark;
}

bool IVector::getMark() const {
    return _mark;
}

IVector * VectorsManager::getVectorByHandler(const VectorHandler & handler) const {
    auto pair = _map.find(handler);
    if (pair == _map.cend())
        return nullptr;
    return pair->second;
}

VectorHandler VectorsManager::applyUniqueHandler() const {
    VectorHandler handler;
    for (uint32_t i = 0; i < sizeof(VectorHandler); ++i) {
        reinterpret_cast<char *>(&handler)[i] = rand() % 0x100;
    }
    while (_map.find(handler) != _map.cend())
        handler += 1;
    return handler;
}

VectorHandler VectorsManager::newVectorVEC() {
    VectorHandler handler = applyUniqueHandler();
    IVector * pVec = new RealVectorEntity<VectorHandler>(handler);
    _map.insert(std::make_pair(handler, pVec));
    return handler;
}

VectorHandler VectorsManager::newVectorB() {
    VectorHandler handler = applyUniqueHandler();
    IVector * pVec = new RealVectorEntity<int8_t>(handler);
    _map.insert(std::make_pair(handler, pVec));
    return handler;
}

VectorHandler VectorsManager::newVectorW() {
    VectorHandler handler = applyUniqueHandler();
    IVector * pVec = new RealVectorEntity<int16_t>(handler);
    _map.insert(std::make_pair(handler, pVec));
    return handler;
}

VectorHandler VectorsManager::newVectorDW() {
    VectorHandler handler = applyUniqueHandler();
    IVector * pVec = new RealVectorEntity<int32_t>(handler);
    _map.insert(std::make_pair(handler, pVec));
    return handler;
}

VectorHandler VectorsManager::newVectorQW() {
    VectorHandler handler = applyUniqueHandler();
    IVector * pVec = new RealVectorEntity<int64_t>(handler);
    _map.insert(std::make_pair(handler, pVec));
    return handler;
}

VectorHandler VectorsManager::newVectorFLT() {
    VectorHandler handler = applyUniqueHandler();
    IVector * pVec = new RealVectorEntity<float>(handler);
    _map.insert(std::make_pair(handler, pVec));
    return handler;
}

VectorHandler VectorsManager::newVectorDBL() {
    VectorHandler handler = applyUniqueHandler();
    IVector * pVec = new RealVectorEntity<double>(handler);
    _map.insert(std::make_pair(handler, pVec));
    return handler;
}

VectorHandler FakeVectorRAM::makeVectorB(uint32_t degree) {
    VectorHandler handler;
    if (degree == 0) {
        handler = _vecman.newVectorB();
        return handler;
    } else {
        handler = _vecman.newVectorVEC();
        IVector *pVec = _vecman.getVectorByHandler(handler);
        RealVectorEntity<VectorHandler> *pNativeVec =
                static_cast<RealVectorEntity<VectorHandler> *>(pVec);
        pNativeVec->set(0, makeVectorB(degree - 1));
        return handler;
    }
}

VectorHandler FakeVectorRAM::makeVectorW(uint32_t degree) {
    VectorHandler handler;
    if (degree == 0) {
        handler = _vecman.newVectorW();
        return handler;
    } else {
        handler = _vecman.newVectorVEC();
        IVector *pVec = _vecman.getVectorByHandler(handler);
        RealVectorEntity<VectorHandler> *pNativeVec =
                static_cast<RealVectorEntity<VectorHandler> *>(pVec);
        pNativeVec->set(0, makeVectorW(degree - 1));
        return handler;
    }
}

VectorHandler FakeVectorRAM::makeVectorDW(uint32_t degree) {
    VectorHandler handler;
    if (degree == 0) {
        handler = _vecman.newVectorDW();
        return handler;
    } else {
        handler = _vecman.newVectorVEC();
        IVector *pVec = _vecman.getVectorByHandler(handler);
        RealVectorEntity<VectorHandler> *pNativeVec =
                static_cast<RealVectorEntity<VectorHandler> *>(pVec);
        pNativeVec->set(0, makeVectorDW(degree - 1));
        return handler;
    }
}

VectorHandler FakeVectorRAM::makeVectorQW(uint32_t degree) {
    VectorHandler handler;
    if (degree == 0) {
        handler = _vecman.newVectorQW();
        return handler;
    } else {
        handler = _vecman.newVectorVEC();
        IVector *pVec = _vecman.getVectorByHandler(handler);
        RealVectorEntity<VectorHandler> *pNativeVec =
                static_cast<RealVectorEntity<VectorHandler> *>(pVec);
        pNativeVec->set(0, makeVectorQW(degree - 1));
        return handler;
    }
}

VectorHandler FakeVectorRAM::makeVectorFLT(uint32_t degree) {
    VectorHandler handler;
    if (degree == 0) {
        handler = _vecman.newVectorFLT();
        return handler;
    } else {
        handler = _vecman.newVectorVEC();
        IVector *pVec = _vecman.getVectorByHandler(handler);
        RealVectorEntity<VectorHandler> *pNativeVec =
                static_cast<RealVectorEntity<VectorHandler> *>(pVec);
        pNativeVec->set(0, makeVectorFLT(degree - 1));
        return handler;
    }
}

VectorHandler FakeVectorRAM::makeVectorDBL(uint32_t degree) {
    VectorHandler handler;
    if (degree == 0) {
        handler = _vecman.newVectorDBL();
        return handler;
    } else {
        handler = _vecman.newVectorVEC();
        IVector *pVec = _vecman.getVectorByHandler(handler);
        RealVectorEntity<VectorHandler> *pNativeVec =
                static_cast<RealVectorEntity<VectorHandler> *>(pVec);
        pNativeVec->set(0, makeVectorDBL(degree - 1));
        return handler;
    }
}

ElemHandler FakeVectorRAM::getOffsetByHandler(const VectorHandler & handler) {
    return _vecman.getVectorByHandler(handler);
    return 0;
}
