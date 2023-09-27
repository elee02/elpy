

// Exercise #3 main()
Point pos3;
pos3.InitMembers(3, 6);
cout << "pos3: [" << pos3.GetX() << ", " << pos3.GetY() << "]" << endl;
if (rec.IsInside(pos3))
    cout << "The pos3 is inside the rectangle." << endl;
else
    cout << "The pos3 is outside the rectangle." << endl;
