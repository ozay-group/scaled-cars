// Generated by gencpp from file rctestpkg/animalAge.msg
// DO NOT EDIT!


#ifndef RCTESTPKG_MESSAGE_ANIMALAGE_H
#define RCTESTPKG_MESSAGE_ANIMALAGE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace rctestpkg
{
template <class ContainerAllocator>
struct animalAge_
{
  typedef animalAge_<ContainerAllocator> Type;

  animalAge_()
    : species()
    , age(0)  {
    }
  animalAge_(const ContainerAllocator& _alloc)
    : species(_alloc)
    , age(0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _species_type;
  _species_type species;

   typedef int64_t _age_type;
  _age_type age;




  typedef boost::shared_ptr< ::rctestpkg::animalAge_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rctestpkg::animalAge_<ContainerAllocator> const> ConstPtr;

}; // struct animalAge_

typedef ::rctestpkg::animalAge_<std::allocator<void> > animalAge;

typedef boost::shared_ptr< ::rctestpkg::animalAge > animalAgePtr;
typedef boost::shared_ptr< ::rctestpkg::animalAge const> animalAgeConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rctestpkg::animalAge_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rctestpkg::animalAge_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace rctestpkg

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'rctestpkg': ['/home/ubuntu/phil_catkin_ws/src/rctestpkg/msg'], 'std_msgs': ['/opt/ros/jade/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::rctestpkg::animalAge_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rctestpkg::animalAge_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rctestpkg::animalAge_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rctestpkg::animalAge_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rctestpkg::animalAge_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rctestpkg::animalAge_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rctestpkg::animalAge_<ContainerAllocator> >
{
  static const char* value()
  {
    return "18f4dd8d566c5f3748f449c6cf5dda79";
  }

  static const char* value(const ::rctestpkg::animalAge_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x18f4dd8d566c5f37ULL;
  static const uint64_t static_value2 = 0x48f449c6cf5dda79ULL;
};

template<class ContainerAllocator>
struct DataType< ::rctestpkg::animalAge_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rctestpkg/animalAge";
  }

  static const char* value(const ::rctestpkg::animalAge_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rctestpkg::animalAge_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string species\n\
int64 age\n\
";
  }

  static const char* value(const ::rctestpkg::animalAge_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rctestpkg::animalAge_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.species);
      stream.next(m.age);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct animalAge_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rctestpkg::animalAge_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rctestpkg::animalAge_<ContainerAllocator>& v)
  {
    s << indent << "species: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.species);
    s << indent << "age: ";
    Printer<int64_t>::stream(s, indent + "  ", v.age);
  }
};

} // namespace message_operations
} // namespace ros

#endif // RCTESTPKG_MESSAGE_ANIMALAGE_H
