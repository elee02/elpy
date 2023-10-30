int main(void) {
    Calculate cc;

    ………

    cout << endl << endl;
    for (i = 0; i < 10; ++i) {
        cout << "Stored the last math operation: ";
        flag = cc.lastOperation(op, value);
        if (!flag)
            cout << "None" << endl;
        else
            cout << op << ", " << value << endl;

        if (flag) {
            
            cc.undo();
            cout << "Undo the last math operation..." << endl;
            cout << "Value inside the class object: ";
            cout << cc.getValue() << endl;
        }
    }
    cout << "Value inside the class object: ";
    cout << cc.getValue() << endl;

    return 0;
}
