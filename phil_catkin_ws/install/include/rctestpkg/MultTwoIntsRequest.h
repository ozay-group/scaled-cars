// Generated by gencpp from file rctestpkg/MultTwoIntsRequest.msg
// DO NOT EDIT!


#ifndef RCTESTPKG_MESSAGE_MULTTWOINTSREQUEST_H
#define RCTESTPKG_MESSAGE_MULTTWOINTSREQUEST_H


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
struct MultTwoIntsRequest_
{
  typedef MultTwoIntsRequest_<ContainerAllocator> Type;

  MultTwoIntsRequest_()
    : a(0)
    , b(0)  {
    }
  MultTwoIntsRequest_(const ContainerAllocator& _alloc)
    : a(0)
    , b(0)  {
  (void)_alloc;
    }



   typedef int64_t _a_type;
  _a_type a;

   typedef int64_t _b_type;
  _b_type b;




  typedef boost::shared_ptr< ::rctestpkg::MultTwoIntsRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rctestpkg::MultTwoIntsRequest_<ContainerAllocator> const> ConstPtr;

}; // struct MultTwoIntsRequest_

typedef ::rctestpkg::MultTwoIntsRequest_<std::allocator<void> > MultTwoIntsRequest;

typedef boost::shared_ptr< ::rctestpkg::MultTwoIntsRequest > MultTwoIntsRequestPtr;
typedef boost::shared_ptr< ::rctestpkg::MultTwoIntsRequest const> MultTwoIntsRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rctestpkg::MultTwoIntsRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rctestpkg::MultTwoIntsRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace rctestpkg

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'rctestpkg': ['/home/ubuntu/phil_catkin_ws/src/rctestpkg/msg'], 'std_msgs': ['/opt/ros/jade/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::rctestpkg::MultTwoIntsRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rctestpkg::MultTwoIntsRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rctestpkg::MultTwoIntsRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rctestpkg::MultTwoIntsRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rctestpkg::MultTwoIntsRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rctestpkg::MultTwoIntsRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rctestpkg::MultTwoIntsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "36d09b846be0b371c5f190354dd3153e";
  }

  static const char* value(const ::rctestpkg::MultTwoIntsRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x36d09b846be0b371ULL;
  static const uint64_t static_value2 = 0xc5f190354dd3153eULL;
};

template<class ContainerAllocator>
struct DataType< ::rctestpkg::MultTwoIntsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rctestpkg/MultTwoIntsRequest";
  }

  static const char* value(const ::rctestpkg::MultTwoIntsRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rctestpkg::MultTwoIntsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 a\n\
int64 b\n\
";
  }

  static const char* value(const ::rctestpkg::MultTwoIntsRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rctestpkg::MultTwoIntsRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.a);
      stream.next(m.b);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MultTwoIntsRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rctestpkg::MultTwoIntsRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rctestpkg::MultTwoIntsRequest_<ContainerAllocator>& v)
  {
    s << indent << "a: ";
    Printer<int64_t>::stream(s, indent + "  ", v.a);
    s << indent << "b: ";
    Printer<int64_t>::stream(s, indent + "  ", v.b);
  }
};

} // namespace message_operations
} // namespace ros

#endif // RCTESTPKG_MESSAGE_MULTTWOINTSREQUEST_H