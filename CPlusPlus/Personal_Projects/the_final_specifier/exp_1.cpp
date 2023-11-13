class A {
public:
    virtual const char* getName() {
        return "A";
    }
};

class B : public A {
public:
    virtual const char* getName() override final {
        return "B";
    }
};

class C : public B {
public:
    virtual const char* getName() override {
        return "C";
    }
};