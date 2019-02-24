//
//  main.cpp
//  eh787_052_P5
//
//  Created by Eric Hyson on 4/24/18.
//  Copyright © 2018 Eric Hyson. All rights reserved.
//

#include "vector.h"
#include "main.h"
#include <iostream>

int main()
{
    
    try
    {
        
        Vector<int> t(10, 10);
        t.push_back(20);
        cout << t.at(10) << endl;
        
        Vector<int> s(20);
        Vector<int> q(10, 22);
        
        
        
        t.insert(0,20);
        t.insert(1,12);
        t.insert(2,13);
        t.insert(3,83);
        t.insert(4,14);
        t.push_back(79);
        t.insert(5, 15);
        
        t.push_back(69);
        
        
        
       
        cout << q.at(0) << endl;
        cout << q.at(1) << endl;
        cout << q.at(2) << endl;
        cout << q.at(3) << endl;
        cout << q.at(4) << endl;
        cout << q.at(5) << endl;
        cout << q.at(6) << endl;
        cout << q.at(7) << endl;
        cout << q.at(8) << endl;
        cout << q.at(9) << endl;
        //cout << q.at(10) << endl;
        //cout << q.at(11) << endl;
        //cout << q.at(12) << endl;
        //cout << q.at(13) << endl;
        //cout << q.at(14) << endl;
        //cout << q.at(15) << endl;
        
        cout << endl << endl << endl;
        
        t.insert(3,21);
        
        
        
        
        
        t.resize(18,333);
            
        cout << t.size() << endl;
        
        cout << t.at(0) << endl;
        cout << t.at(1) << endl;
        cout << t.at(2) << endl;
        cout << t.at(3) << endl;
        cout << t.at(4) << endl;
        cout << t.at(5) << endl;
        cout << t.at(6) << endl;
        cout << t.at(7) << endl;
        cout << t.at(8) << endl;
        cout << t.at(9) << endl;
        cout << t.at(10) << endl;
        cout << t.at(11) << endl;
        cout << t.at(11) << endl;
        
       
        cout << endl << endl << endl;
        
        s.sort();
        s.assign(3, 11000);
        cout << s.at(0) << endl;
        cout << s.at(1) << endl;
        cout << s.at(2) << endl;
        cout << s.at(3) << endl;
        cout << s.at(4) << endl;
        cout << s.at(5) << endl;
         
        cout << s.at(6) << endl;
        cout << s.at(7) << endl;
        cout << s.at(8) << endl;
        cout << s.at(9) << endl;
        cout << s.at(10) << endl;
        cout << s.at(11) << endl;
        
        
        
    
    }
    catch(out_of_range &e)
    {
        cout << e.what() << endl;
    }
    catch(...)
    {
        cout << "unknowen error" << endl;
    }


}
