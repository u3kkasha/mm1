#ifndef AUTO_ENABLED_ID_H
#define AUTO_ENABLED_ID_H

template <typename Client_Class> class Auto_enabled_id {
private:
  static inline int total_number_of_objects_created = 0;
  int const id;
protected:
  Auto_enabled_id() : id(total_number_of_objects_created++) {}
  [[no_discard]] int get_id() { return id; }
};

#endif // AUTO_ENABLED_ID_H