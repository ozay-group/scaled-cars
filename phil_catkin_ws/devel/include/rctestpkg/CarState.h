// Generated by gencpp from file rctestpkg/CarState.msg
// DO NOT EDIT!


#ifndef RCTESTPKG_MESSAGE_CARSTATE_H
#define RCTESTPKG_MESSAGE_CARSTATE_H


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
struct CarState_
{
  typedef CarState_<ContainerAllocator> Type;

  CarState_()
    : time(0.0)
    , x_global(0.0)
    , y_global(0.0)
    , yaw_global(0.0)
    , h(0.0)
    , vl(0.0)
    , u(0.0)
    , y(0.0)
    , v(0.0)
    , psi(0.0)
    , r(0.0)
    , rd(0.0)  {
    }
  CarState_(const ContainerAllocator& _alloc)
    : time(0.0)
    , x_global(0.0)
    , y_global(0.0)
    , yaw_global(0.0)
    , h(0.0)
    , vl(0.0)
    , u(0.0)
    , y(0.0)
    , v(0.0)
    , psi(0.0)
    , r(0.0)
    , rd(0.0)  {
  (void)_alloc;
    }



   typedef double _time_type;
  _time_type time;

   typedef double _x_global_type;
  _x_global_type x_global;

   typedef double _y_global_type;
  _y_global_type y_global;

   typedef double _yaw_global_type;
  _yaw_global_type yaw_global;

   typedef double _h_type;
  _h_type h;

   typedef double _vl_type;
  _vl_type vl;

   typedef double _u_type;
  _u_type u;

   typedef double _y_type;
  _y_type y;

   typedef double _v_type;
  _v_type v;

   typedef double _psi_type;
  _psi_type psi;

   typedef double _r_type;
  _r_type r;

   typedef double _rd_type;
  _rd_type rd;




  typedef boost::shared_ptr< ::rctestpkg::CarState_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rctestpkg::CarState_<ContainerAllocator> const> ConstPtr;

}; // struct CarState_

typedef ::rctestpkg::CarState_<std::allocator<void> > CarState;

typedef boost::shared_ptr< ::rctestpkg::CarState > CarStatePtr;
typedef boost::shared_ptr< ::rctestpkg::CarState const> CarStateConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rctestpkg::CarState_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rctestpkg::CarState_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace rctestpkg

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'rctestpkg': ['/home/ubuntu/phil_catkin_ws/src/rctestpkg/msg'], 'sensor_msgs': ['/opt/ros/jade/share/sensor_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/jade/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/jade/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::rctestpkg::CarState_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rctestpkg::CarState_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rctestpkg::CarState_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rctestpkg::CarState_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rctestpkg::CarState_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rctestpkg::CarState_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rctestpkg::CarState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "5c168035e6a7af9bba6d62e824c5dd6a";
  }

  static const char* value(const ::rctestpkg::CarState_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x5c168035e6a7af9bULL;
  static const uint64_t static_value2 = 0xba6d62e824c5dd6aULL;
};

template<class ContainerAllocator>
struct DataType< ::rctestpkg::CarState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rctestpkg/CarState";
  }

  static const char* value(const ::rctestpkg::CarState_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rctestpkg::CarState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 time\n\
float64 x_global\n\
float64 y_global\n\
float64 yaw_global\n\
float64 h\n\
float64 vl\n\
float64 u\n\
float64 y\n\
float64 v\n\
float64 psi\n\
float64 r\n\
float64 rd\n\
";
  }

  static const char* value(const ::rctestpkg::CarState_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rctestpkg::CarState_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.time);
      stream.next(m.x_global);
      stream.next(m.y_global);
      stream.next(m.yaw_global);
      stream.next(m.h);
      stream.next(m.vl);
      stream.next(m.u);
      stream.next(m.y);
      stream.next(m.v);
      stream.next(m.psi);
      stream.next(m.r);
      stream.next(m.rd);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CarState_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rctestpkg::CarState_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rctestpkg::CarState_<ContainerAllocator>& v)
  {
    s << indent << "time: ";
    Printer<double>::stream(s, indent + "  ", v.time);
    s << indent << "x_global: ";
    Printer<double>::stream(s, indent + "  ", v.x_global);
    s << indent << "y_global: ";
    Printer<double>::stream(s, indent + "  ", v.y_global);
    s << indent << "yaw_global: ";
    Printer<double>::stream(s, indent + "  ", v.yaw_global);
    s << indent << "h: ";
    Printer<double>::stream(s, indent + "  ", v.h);
    s << indent << "vl: ";
    Printer<double>::stream(s, indent + "  ", v.vl);
    s << indent << "u: ";
    Printer<double>::stream(s, indent + "  ", v.u);
    s << indent << "y: ";
    Printer<double>::stream(s, indent + "  ", v.y);
    s << indent << "v: ";
    Printer<double>::stream(s, indent + "  ", v.v);
    s << indent << "psi: ";
    Printer<double>::stream(s, indent + "  ", v.psi);
    s << indent << "r: ";
    Printer<double>::stream(s, indent + "  ", v.r);
    s << indent << "rd: ";
    Printer<double>::stream(s, indent + "  ", v.rd);
  }
};

} // namespace message_operations
} // namespace ros

#endif // RCTESTPKG_MESSAGE_CARSTATE_H
