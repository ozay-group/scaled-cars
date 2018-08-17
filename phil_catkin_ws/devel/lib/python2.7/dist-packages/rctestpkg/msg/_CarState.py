# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from rctestpkg/CarState.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class CarState(genpy.Message):
  _md5sum = "5c168035e6a7af9bba6d62e824c5dd6a"
  _type = "rctestpkg/CarState"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """float64 time
float64 x_global
float64 y_global
float64 yaw_global
float64 h
float64 vl
float64 u
float64 y
float64 v
float64 psi
float64 r
float64 rd
"""
  __slots__ = ['time','x_global','y_global','yaw_global','h','vl','u','y','v','psi','r','rd']
  _slot_types = ['float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       time,x_global,y_global,yaw_global,h,vl,u,y,v,psi,r,rd

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(CarState, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.time is None:
        self.time = 0.
      if self.x_global is None:
        self.x_global = 0.
      if self.y_global is None:
        self.y_global = 0.
      if self.yaw_global is None:
        self.yaw_global = 0.
      if self.h is None:
        self.h = 0.
      if self.vl is None:
        self.vl = 0.
      if self.u is None:
        self.u = 0.
      if self.y is None:
        self.y = 0.
      if self.v is None:
        self.v = 0.
      if self.psi is None:
        self.psi = 0.
      if self.r is None:
        self.r = 0.
      if self.rd is None:
        self.rd = 0.
    else:
      self.time = 0.
      self.x_global = 0.
      self.y_global = 0.
      self.yaw_global = 0.
      self.h = 0.
      self.vl = 0.
      self.u = 0.
      self.y = 0.
      self.v = 0.
      self.psi = 0.
      self.r = 0.
      self.rd = 0.

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_struct_12d.pack(_x.time, _x.x_global, _x.y_global, _x.yaw_global, _x.h, _x.vl, _x.u, _x.y, _x.v, _x.psi, _x.r, _x.rd))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 96
      (_x.time, _x.x_global, _x.y_global, _x.yaw_global, _x.h, _x.vl, _x.u, _x.y, _x.v, _x.psi, _x.r, _x.rd,) = _struct_12d.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_struct_12d.pack(_x.time, _x.x_global, _x.y_global, _x.yaw_global, _x.h, _x.vl, _x.u, _x.y, _x.v, _x.psi, _x.r, _x.rd))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 96
      (_x.time, _x.x_global, _x.y_global, _x.yaw_global, _x.h, _x.vl, _x.u, _x.y, _x.v, _x.psi, _x.r, _x.rd,) = _struct_12d.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_12d = struct.Struct("<12d")
