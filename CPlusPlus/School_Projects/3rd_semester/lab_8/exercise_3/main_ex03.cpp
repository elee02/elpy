int main(void) {
    Calculate cc;

    ………

    Calculate dd{ cc };

    cout << endl << endl;
    for (i = 0; i < 10; ++i) {
        cout << "Stored the last math operation: ";
        flag = dd.lastOperation(op, value);
        if (!flag)
            cout << "None" << endl;
        else
            cout << op << ", " << value << endl;

        if (flag) {
            dd.undo();
            cout << "Undo the last math operation..." << endl;
            cout << "Value inside the class object: ";
            cout << dd.getValue() << endl;
        }
    }
    cout << "Value inside the class object: ";
    cout << dd.getValue() << endl;

    return 0;
}
