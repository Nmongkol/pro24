#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void printList(list<string> s) {
    list<string>::iterator i;
    for (i = s.begin(); i != s.end(); i++) {
        cout << *i << " ";
    }
    cout << "\n";
}

int main() {
    list<string> line_up;
    list<string>::iterator loc;

    line_up.push_back("Alice"); // Alice ปวดขี้และมายืนรอคิวเป็นคนแรก
    line_up.push_back("Bob");   // Bob มาต่อแถว

    loc = find(line_up.begin(), line_up.end(), "Bob");
    line_up.insert(loc, "Oscar"); // Oscar มาแซงแถวหน้า Bob

    // Luffy, Sanji, Nami มาต่อแถวด้านหลังตามลำดับ
    line_up.push_back("Luffy");
    line_up.push_back("Sanji");
    line_up.push_back("Nami");

    // 2 คนที่หัวแถวได้เข้าไปในส้วมแล้ว
    line_up.pop_front(); // Alice
    line_up.pop_front(); // Oscar

    // Narutu มาแทรกแถวหลัง Luffy
    loc = find(line_up.begin(), line_up.end(), "Luffy");
    line_up.insert(++loc, "Narutu"); // แทรกหลัง Luffy

    // Prayath ท้องเสียปวดขี้สุด ๆ เลยมาแทรกแซวหน้าสุด
    line_up.push_front("Prayath"); // แทรกข้างหน้า

    // Tony ยอมไม่ได้เลยมาแทรกด้านหลัง Prayath
    loc = line_up.begin();
    line_up.insert(++loc, "Tony"); // แทรกหลัง Prayath

    // Bob ทนไม่ไหวเลย เลยเปลี่ยนใจออกไปขี้ที่อื่น
    loc = find(line_up.begin(), line_up.end(), "Bob");
    if (loc != line_up.end()) {
        line_up.erase(loc); // ลบ Bob
    }

    // 3 คนที่หัวแถวได้เข้าไปในส้วมแล้ว
    line_up.pop_front(); // Prayath
    line_up.pop_front(); // Tony
    line_up.pop_front(); // Narutu

    // สุดท้าย Function printList() จะแสดงลำดับของผู้ที่ยังเหลืออยู่ในคิว
    printList(line_up); // ควรแสดง: Sanji Nami 

    return 0;
}
