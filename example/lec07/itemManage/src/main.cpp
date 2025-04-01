#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Item {
public:
  using id_t = unsigned long;
  static shared_ptr<Item> make_item(const string &name) {
    Item *pointer = new Item(name);
    shared_ptr<Item> item(pointer);
    item->id = nextId();
    items[item->id] = item.get();
    return item;
  }

  // cannot be copied
  Item(const Item &) = delete;
  void operator=(const Item &) = delete;

  ~Item() { items.erase(items.find(id)); }

  static Item *get_by_id(id_t id) { return items[id]; }

  static int count() { return items.size(); }

  string to_string() const {
    ostringstream oss;
    oss << "Item " << id << ": " << name;
    return oss.str();
  }

private:
  static unordered_map<id_t, Item *> items;
  explicit Item(const string &name) : name(name) {}
  id_t id;
  string name;

  static id_t nextId() {
    id_t r = 0;
    while (items.find(r) != items.end())
      r++;
    return r;
  }
};

unordered_map<Item::id_t, Item *> Item::items;

int main() {
  vector<shared_ptr<Item>> items;
  int num = 10;
  for (int i = 0; i < num; i++) {
    items.push_back(Item::make_item("Name" + to_string(i)));
  }
  auto it = items.begin();
  cout << Item::count() << endl;
  items.erase(++it);
  cout << Item::count() << endl;

  // you can try this
  // Item itm = *items[1];
  // *items[1] = *items[2];

  items.push_back(Item::make_item("One more thing!"));

  for (auto &item : items)
    cout << item->to_string() << endl;
  return 0;
}
