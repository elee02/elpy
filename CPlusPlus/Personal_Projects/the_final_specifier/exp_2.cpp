class A {
public:
    virtual const char* getName() {
        return "A";
    }
};

class B final : public A {
public:
    virtual const char* getName() override {
        return "B";
    }
};

class C : public B {
public:
    virtual const char* getName() override {
        return "C";
    }
};