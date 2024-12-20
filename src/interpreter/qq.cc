#define REGISTER_INPUT_OPERAND_TYPE_LIST(V)        \
  V(Reg, OperandTypeInfo::kScalableSignedByte)     \
  V(RegList, OperandTypeInfo::kScalableSignedByte) \
  V(RegPair, OperandTypeInfo::kScalableSignedByte)

#define REGISTER_OUTPUT_OPERAND_TYPE_LIST(V)          \
  V(RegOut, OperandTypeInfo::kScalableSignedByte)     \
  V(RegOutList, OperandTypeInfo::kScalableSignedByte) \
  V(RegOutPair, OperandTypeInfo::kScalableSignedByte) \
  V(RegOutTriple, OperandTypeInfo::kScalableSignedByte)

#define SIGNED_SCALABLE_SCALAR_OPERAND_TYPE_LIST(V) \
  V(Imm, OperandTypeInfo::kScalableSignedByte)

#define UNSIGNED_SCALABLE_SCALAR_OPERAND_TYPE_LIST(V) \
  V(Idx, OperandTypeInfo::kScalableUnsignedByte)      \
  V(UImm, OperandTypeInfo::kScalableUnsignedByte)     \
  V(RegCount, OperandTypeInfo::kScalableUnsignedByte)

#define REGISTER_OPERAND_TYPE_LIST(V)  \
  REGISTER_INPUT_OPERAND_TYPE_LIST(V)  \
  REGISTER_OUTPUT_OPERAND_TYPE_LIST(V) \
  V(RegInOut, OperandTypeInfo::kScalableSignedByte)
