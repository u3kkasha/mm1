#ifndef AUTO_ENABLED_ID_H
#define AUTO_ENABLED_ID_H

template <typename Client_Class> class Auto_enabled_id {
protected:
  static inline int total_number_of_objects_created = 0;
  int id;
  Auto_enabled_id() : id(total_number_of_objects_created++) {}

  int get_id() { return id; }
};

#endif // AUTO_ENABLED_ID_H