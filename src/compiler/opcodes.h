// Copyright 2013 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef V8_COMPILER_OPCODES_H_
#define V8_COMPILER_OPCODES_H_

#include <iosfwd>

#include "src/common/globals.h"

// Opcodes for control operators.
#define CONTROL_OP_LIST(V)           \
  V(Start)                           \
  V(Loop)                            \
  V(Branch)                          \
  V(Switch)                          \
  V(IfTrue)                          \
  V(IfFalse)                         \
  V(IfSuccess)                       \
  V(IfException)                     \
  V(IfValue)                         \
  V(IfDefault)                       \
  V(Merge)                           \
  V(Deoptimize)                      \
  V(DeoptimizeIf)                    \
  V(DeoptimizeUnless)                \
  V(DynamicCheckMapsWithDeoptUnless) \
  V(TrapIf)                          \
  V(TrapUnless)                      \
  V(Return)                          \
  V(TailCall)                        \
  V(Terminate)                       \
  V(Throw)                           \
  V(End)

// Opcodes for constant operators.
#define CONSTANT_OP_LIST(V)   \
  V(Int32Constant)            \
  V(Int64Constant)            \
  V(TaggedIndexConstant)      \
  V(Float32Constant)          \
  V(Float64Constant)          \
  V(ExternalConstant)         \
  V(NumberConstant)           \
  V(PointerConstant)          \
  V(HeapConstant)             \
  V(CompressedHeapConstant)   \
  V(RelocatableInt32Constant) \
  V(RelocatableInt64Constant)

#define INNER_OP_LIST(V)    \
  V(Select)                 \
  V(Phi)                    \
  V(EffectPhi)              \
  V(InductionVariablePhi)   \
  V(Checkpoint)             \
  V(BeginRegion)            \
  V(FinishRegion)           \
  V(FrameState)             \
  V(StateValues)            \
  V(TypedStateValues)       \
  V(ArgumentsElementsState) \
  V(ArgumentsLengthState)   \
  V(ObjectState)            \
  V(ObjectId)               \
  V(TypedObjectState)       \
  V(Call)                   \
  V(Parameter)              \
  V(OsrValue)               \
  V(LoopExit)               \
  V(LoopExitValue)          \
  V(LoopExitEffect)         \
  V(Projection)             \
  V(Retain)                 \
  V(MapGuard)               \
  V(FoldConstant)           \
  V(TypeGuard)

#define COMMON_OP_LIST(V) \
  CONSTANT_OP_LIST(V)     \
  INNER_OP_LIST(V)        \
  V(Unreachable)          \
  V(DeadValue)            \
  V(Dead)                 \
  V(StaticAssert)

// Opcodes for JavaScript operators.
// Arguments are JSName (the name with a 'JS' prefix), and Name.
#define JS_COMPARE_BINOP_LIST(V)        \
  V(JSEqual, Equal)                     \
  V(JSStrictEqual, StrictEqual)         \
  V(JSLessThan, LessThan)               \
  V(JSGreaterThan, GreaterThan)         \
  V(JSLessThanOrEqual, LessThanOrEqual) \
  V(JSGreaterThanOrEqual, GreaterThanOrEqual)

#define JS_BITWISE_BINOP_LIST(V) \
  V(JSBitwiseOr, BitwiseOr)      \
  V(JSBitwiseXor, BitwiseXor)    \
  V(JSBitwiseAnd, BitwiseAnd)    \
  V(JSShiftLeft, ShiftLeft)      \
  V(JSShiftRight, ShiftRight)    \
  V(JSShiftRightLogical, ShiftRightLogical)

#define JS_ARITH_BINOP_LIST(V) \
  V(JSAdd, Add)                \
  V(JSSubtract, Subtract)      \
  V(JSMultiply, Multiply)      \
  V(JSDivide, Divide)          \
  V(JSModulus, Modulus)        \
  V(JSExponentiate, Exponentiate)

#define JS_SIMPLE_BINOP_LIST(V) \
  JS_COMPARE_BINOP_LIST(V)      \
  JS_BITWISE_BINOP_LIST(V)      \
  JS_ARITH_BINOP_LIST(V)        \
  V(JSHasInPrototypeChain)      \
  V(JSInstanceOf)               \
  V(JSOrdinaryHasInstance)

#define JS_CONVERSION_UNOP_LIST(V) \
  V(JSToLength)                    \
  V(JSToName)                      \
  V(JSToNumber)                    \
  V(JSToNumberConvertBigInt)       \
  V(JSToNumeric)                   \
  V(JSToObject)                    \
  V(JSToString)                    \
  V(JSParseInt)

#define JS_BITWISE_UNOP_LIST(V) \
  V(JSBitwiseNot, BitwiseNot)   \
  V(JSNegate, Negate)

#define JS_ARITH_UNOP_LIST(V) \
  V(JSDecrement, Decrement)   \
  V(JSIncrement, Increment)

#define JS_SIMPLE_UNOP_LIST(V) \
  JS_ARITH_UNOP_LIST(V)        \
  JS_BITWISE_UNOP_LIST(V)      \
  JS_CONVERSION_UNOP_LIST(V)

#define JS_CREATE_OP_LIST(V)     \
  V(JSCloneObject)               \
  V(JSCreate)                    \
  V(JSCreateArguments)           \
  V(JSCreateArray)               \
  V(JSCreateArrayFromIterable)   \
  V(JSCreateArrayIterator)       \
  V(JSCreateAsyncFunctionObject) \
  V(JSCreateBoundFunction)       \
  V(JSCreateClosure)             \
  V(JSCreateCollectionIterator)  \
  V(JSCreateEmptyLiteralArray)   \
  V(JSCreateEmptyLiteralObject)  \
  V(JSCreateGeneratorObject)     \
  V(JSCreateIterResultObject)    \
  V(JSCreateKeyValueArray)       \
  V(JSCreateLiteralArray)        \
  V(JSCreateLiteralObject)       \
  V(JSCreateLiteralRegExp)       \
  V(JSCreateObject)              \
  V(JSCreatePromise)             \
  V(JSCreateStringIterator)      \
  V(JSCreateTypedArray)          \
  V(JSGetTemplateObject)

#define JS_OBJECT_OP_LIST(V)      \
  JS_CREATE_OP_LIST(V)            \
  V(JSLoadProperty)               \
  V(JSLoadNamed)                  \
  V(JSLoadNamedFromSuper)         \
  V(JSLoadGlobal)                 \
  V(JSStoreProperty)              \
  V(JSStoreNamed)                 \
  V(JSStoreNamedOwn)              \
  V(JSStoreGlobal)                \
  V(JSStoreDataPropertyInLiteral) \
  V(JSStoreInArrayLiteral)        \
  V(JSDeleteProperty)             \
  V(JSHasProperty)                \
  V(JSGetSuperConstructor)

#define JS_CONTEXT_OP_LIST(V) \
  V(JSHasContextExtension)    \
  V(JSLoadContext)            \
  V(JSStoreContext)           \
  V(JSCreateFunctionContext)  \
  V(JSCreateCatchContext)     \
  V(JSCreateWithContext)      \
  V(JSCreateBlockContext)

#define JS_CALL_OP_LIST(V) \
  V(JSCall)                \
  V(JSCallForwardVarargs)  \
  V(JSCallWithArrayLike)   \
  V(JSCallWithSpread)      \
  IF_WASM(V, JSWasmCall)

#define JS_CONSTRUCT_OP_LIST(V) \
  V(JSConstructForwardVarargs)  \
  V(JSConstruct)                \
  V(JSConstructWithArrayLike)   \
  V(JSConstructWithSpread)

#define JS_OTHER_OP_LIST(V)            \
  JS_CALL_OP_LIST(V)                   \
  JS_CONSTRUCT_OP_LIST(V)              \
  V(JSAsyncFunctionEnter)              \
  V(JSAsyncFunctionReject)             \
  V(JSAsyncFunctionResolve)            \
  V(JSCallRuntime)                     \
  V(JSForInEnumerate)                  \
  V(JSForInNext)                       \
  V(JSForInPrepare)                    \
  V(JSGetIterator)                     \
  V(JSLoadMessage)                     \
  V(JSStoreMessage)                    \
  V(JSLoadModule)                      \
  V(JSStoreModule)                     \
  V(JSGetImportMeta)                   \
  V(JSGeneratorStore)                  \
  V(JSGeneratorRestoreContinuation)    \
  V(JSGeneratorRestoreContext)         \
  V(JSGeneratorRestoreRegister)        \
  V(JSGeneratorRestoreInputOrDebugPos) \
  V(JSFulfillPromise)                  \
  V(JSPerformPromiseThen)              \
  V(JSPromiseResolve)                  \
  V(JSRejectPromise)                   \
  V(JSResolvePromise)                  \
  V(JSStackCheck)                      \
  V(JSObjectIsArray)                   \
  V(JSRegExpTest)                      \
  V(JSDebugger)

#define JS_OP_LIST(V)     \
  JS_SIMPLE_BINOP_LIST(V) \
  JS_SIMPLE_UNOP_LIST(V)  \
  JS_OBJECT_OP_LIST(V)    \
  JS_CONTEXT_OP_LIST(V)   \
  JS_OTHER_OP_LIST(V)

// Opcodes for VirtuaMachine-level operators.
#define SIMPLIFIED_CHANGE_OP_LIST(V) \
  V(ChangeTaggedSignedToInt32)       \
  V(ChangeTaggedSignedToInt64)       \
  V(ChangeTaggedToInt32)             \
  V(ChangeTaggedToInt64)             \
  V(ChangeTaggedToUint32)            \
  V(ChangeTaggedToFloat64)           \
  V(ChangeTaggedToTaggedSigned)      \
  V(ChangeInt31ToTaggedSigned)       \
  V(ChangeInt32ToTagged)             \
  V(ChangeInt64ToTagged)             \
  V(ChangeUint32ToTagged)            \
  V(ChangeUint64ToTagged)            \
  V(ChangeFloat64ToTagged)           \
  V(ChangeFloat64ToTaggedPointer)    \
  V(ChangeTaggedToBit)               \
  V(ChangeBitToTagged)               \
  V(ChangeUint64ToBigInt)            \
  V(TruncateBigIntToUint64)          \
  V(TruncateTaggedToWord32)          \
  V(TruncateTaggedToFloat64)         \
  V(TruncateTaggedToBit)             \
  V(TruncateTaggedPointerToBit)

#define SIMPLIFIED_CHECKED_OP_LIST(V) \
  V(CheckedInt32Add)                  \
  V(CheckedInt32Sub)                  \
  V(CheckedInt32Div)                  \
  V(CheckedInt32Mod)                  \
  V(CheckedUint32Div)                 \
  V(CheckedUint32Mod)                 \
  V(CheckedInt32Mul)                  \
  V(CheckedInt32ToTaggedSigned)       \
  V(CheckedInt64ToInt32)              \
  V(CheckedInt64ToTaggedSigned)       \
  V(CheckedUint32Bounds)              \
  V(CheckedUint32ToInt32)             \
  V(CheckedUint32ToTaggedSigned)      \
  V(CheckedUint64Bounds)              \
  V(CheckedUint64ToInt32)             \
  V(CheckedUint64ToTaggedSigned)      \
  V(CheckedFloat64ToInt32)            \
  V(CheckedFloat64ToInt64)            \
  V(CheckedTaggedSignedToInt32)       \
  V(CheckedTaggedToInt32)             \
  V(CheckedTaggedToArrayIndex)        \
  V(CheckedTruncateTaggedToWord32)    \
  V(CheckedTaggedToFloat64)           \
  V(CheckedTaggedToInt64)             \
  V(CheckedTaggedToTaggedSigned)      \
  V(CheckedTaggedToTaggedPointer)

#define SIMPLIFIED_COMPARE_BINOP_LIST(V) \
  V(NumberEqual)                         \
  V(NumberLessThan)                      \
  V(NumberLessThanOrEqual)               \
  V(SpeculativeNumberEqual)              \
  V(SpeculativeNumberLessThan)           \
  V(SpeculativeNumberLessThanOrEqual)    \
  V(ReferenceEqual)                      \
  V(SameValue)                           \
  V(SameValueNumbersOnly)                \
  V(NumberSameValue)                     \
  V(StringEqual)                         \
  V(StringLessThan)                      \
  V(StringLessThanOrEqual)

#define SIMPLIFIED_NUMBER_BINOP_LIST(V) \
  V(NumberAdd)                          \
  V(NumberSubtract)                     \
  V(NumberMultiply)                     \
  V(NumberDivide)                       \
  V(NumberModulus)                      \
  V(NumberBitwiseOr)                    \
  V(NumberBitwiseXor)                   \
  V(NumberBitwiseAnd)                   \
  V(NumberShiftLeft)                    \
  V(NumberShiftRight)                   \
  V(NumberShiftRightLogical)            \
  V(NumberAtan2)                        \
  V(NumberImul)                         \
  V(NumberMax)                          \
  V(NumberMin)                          \
  V(NumberPow)

#define SIMPLIFIED_BIGINT_BINOP_LIST(V) \
  V(BigIntAdd)                          \
  V(BigIntSubtract)

#define SIMPLIFIED_SPECULATIVE_NUMBER_BINOP_LIST(V) \
  V(SpeculativeNumberAdd)                           \
  V(SpeculativeNumberSubtract)                      \
  V(SpeculativeNumberMultiply)                      \
  V(SpeculativeNumberPow)                           \
  V(SpeculativeNumberDivide)                        \
  V(SpeculativeNumberModulus)                       \
  V(SpeculativeNumberBitwiseAnd)                    \
  V(SpeculativeNumberBitwiseOr)                     \
  V(SpeculativeNumberBitwiseXor)                    \
  V(SpeculativeNumberShiftLeft)                     \
  V(SpeculativeNumberShiftRight)                    \
  V(SpeculativeNumberShiftRightLogical)             \
  V(SpeculativeSafeIntegerAdd)                      \
  V(SpeculativeSafeIntegerSubtract)

#define SIMPLIFIED_NUMBER_UNOP_LIST(V) \
  V(NumberAbs)                         \
  V(NumberAcos)                        \
  V(NumberAcosh)                       \
  V(NumberAsin)                        \
  V(NumberAsinh)                       \
  V(NumberAtan)                        \
  V(NumberAtanh)                       \
  V(NumberCbrt)                        \
  V(NumberCeil)                        \
  V(NumberClz32)                       \
  V(NumberCos)                         \
  V(NumberCosh)                        \
  V(NumberExp)                         \
  V(NumberExpm1)                       \
  V(NumberFloor)                       \
  V(NumberFround)                      \
  V(NumberLog)                         \
  V(NumberLog1p)                       \
  V(NumberLog2)                        \
  V(NumberLog10)                       \
  V(NumberRound)                       \
  V(NumberSign)                        \
  V(NumberSin)                         \
  V(NumberSinh)                        \
  V(NumberSqrt)                        \
  V(NumberTan)                         \
  V(NumberTanh)                        \
  V(NumberTrunc)                       \
  V(NumberToBoolean)                   \
  V(NumberToInt32)                     \
  V(NumberToString)                    \
  V(NumberToUint32)                    \
  V(NumberToUint8Clamped)              \
  V(NumberSilenceNaN)

#define SIMPLIFIED_BIGINT_UNOP_LIST(V) \
  V(BigIntNegate)                      \
  V(CheckBigInt)

#define SIMPLIFIED_SPECULATIVE_NUMBER_UNOP_LIST(V) V(SpeculativeToNumber)

#define SIMPLIFIED_OTHER_OP_LIST(V)     \
  V(Allocate)                           \
  V(AllocateRaw)                        \
  V(ArgumentsLength)                    \
  V(AssertType)                         \
  V(BooleanNot)                         \
  V(CheckBounds)                        \
  V(CheckClosure)                       \
  V(CheckEqualsInternalizedString)      \
  V(CheckEqualsSymbol)                  \
  V(CheckFloat64Hole)                   \
  V(CheckHeapObject)                    \
  V(CheckIf)                            \
  V(CheckInternalizedString)            \
  V(CheckMaps)                          \
  V(CheckNotTaggedHole)                 \
  V(CheckNumber)                        \
  V(CheckReceiver)                      \
  V(CheckReceiverOrNullOrUndefined)     \
  V(CheckSmi)                           \
  V(CheckString)                        \
  V(CheckSymbol)                        \
  V(CompareMaps)                        \
  V(ConvertReceiver)                    \
  V(ConvertTaggedHoleToUndefined)       \
  V(DateNow)                            \
  V(DelayedStringConstant)              \
  V(DynamicCheckMaps)                   \
  V(EnsureWritableFastElements)         \
  V(FastApiCall)                        \
  V(FindOrderedHashMapEntry)            \
  V(FindOrderedHashMapEntryForInt32Key) \
  V(LoadDataViewElement)                \
  V(LoadElement)                        \
  V(LoadField)                          \
  V(LoadFieldByIndex)                   \
  V(LoadFromObject)                     \
  V(LoadMessage)                        \
  V(LoadStackArgument)                  \
  V(LoadTypedElement)                   \
  V(MaybeGrowFastElements)              \
  V(NewArgumentsElements)               \
  V(NewConsString)                      \
  V(NewDoubleElements)                  \
  V(NewSmiOrObjectElements)             \
  V(NumberIsFinite)                     \
  V(NumberIsFloat64Hole)                \
  V(NumberIsInteger)                    \
  V(NumberIsMinusZero)                  \
  V(NumberIsNaN)                        \
  V(NumberIsSafeInteger)                \
  V(ObjectIsArrayBufferView)            \
  V(ObjectIsBigInt)                     \
  V(ObjectIsCallable)                   \
  V(ObjectIsConstructor)                \
  V(ObjectIsDetectableCallable)         \
  V(ObjectIsFiniteNumber)               \
  V(ObjectIsInteger)                    \
  V(ObjectIsMinusZero)                  \
  V(ObjectIsNaN)                        \
  V(ObjectIsNonCallable)                \
  V(ObjectIsNumber)                     \
  V(ObjectIsReceiver)                   \
  V(ObjectIsSafeInteger)                \
  V(ObjectIsSmi)                        \
  V(ObjectIsString)                     \
  V(ObjectIsSymbol)                     \
  V(ObjectIsUndetectable)               \
  V(PlainPrimitiveToFloat64)            \
  V(PlainPrimitiveToNumber)             \
  V(PlainPrimitiveToWord32)             \
  V(PoisonIndex)                        \
  V(RestLength)                         \
  V(RuntimeAbort)                       \
  V(StoreDataViewElement)               \
  V(StoreElement)                       \
  V(StoreField)                         \
  V(StoreMessage)                       \
  V(StoreSignedSmallElement)            \
  V(StoreToObject)                      \
  V(StoreTypedElement)                  \
  V(StringCharCodeAt)                   \
  V(StringCodePointAt)                  \
  V(StringConcat)                       \
  V(StringFromCodePointAt)              \
  V(StringFromSingleCharCode)           \
  V(StringFromSingleCodePoint)          \
  V(StringIndexOf)                      \
  V(StringLength)                       \
  V(StringSubstring)                    \
  V(StringToLowerCaseIntl)              \
  V(StringToNumber)                     \
  V(StringToUpperCaseIntl)              \
  V(TierUpCheck)                        \
  V(ToBoolean)                          \
  V(TransitionAndStoreElement)          \
  V(TransitionAndStoreNonNumberElement) \
  V(TransitionAndStoreNumberElement)    \
  V(TransitionElementsKind)             \
  V(TypeOf)                             \
  V(UpdateInterruptBudget)              \
  V(VerifyType)

#define SIMPLIFIED_SPECULATIVE_BIGINT_BINOP_LIST(V) \
  V(SpeculativeBigIntAdd)                           \
  V(SpeculativeBigIntSubtract)

#define SIMPLIFIED_SPECULATIVE_BIGINT_UNOP_LIST(V) \
  V(SpeculativeBigIntAsUintN)                      \
  V(SpeculativeBigIntNegate)

#define SIMPLIFIED_OP_LIST(V)                 \
  SIMPLIFIED_CHANGE_OP_LIST(V)                \
  SIMPLIFIED_CHECKED_OP_LIST(V)               \
  SIMPLIFIED_COMPARE_BINOP_LIST(V)            \
  SIMPLIFIED_NUMBER_BINOP_LIST(V)             \
  SIMPLIFIED_BIGINT_BINOP_LIST(V)             \
  SIMPLIFIED_SPECULATIVE_NUMBER_BINOP_LIST(V) \
  SIMPLIFIED_NUMBER_UNOP_LIST(V)              \
  SIMPLIFIED_BIGINT_UNOP_LIST(V)              \
  SIMPLIFIED_SPECULATIVE_NUMBER_UNOP_LIST(V)  \
  SIMPLIFIED_SPECULATIVE_BIGINT_UNOP_LIST(V)  \
  SIMPLIFIED_SPECULATIVE_BIGINT_BINOP_LIST(V) \
  SIMPLIFIED_OTHER_OP_LIST(V)

// Opcodes for Machine-level operators.
#define MACHINE_COMPARE_BINOP_LIST(V) \
  V(Word32Equal)                      \
  V(Word64Equal)                      \
  V(Int32LessThan)                    \
  V(Int32LessThanOrEqual)             \
  V(Uint32LessThan)                   \
  V(Uint32LessThanOrEqual)            \
  V(Int64LessThan)                    \
  V(Int64LessThanOrEqual)             \
  V(Uint64LessThan)                   \
  V(Uint64LessThanOrEqual)            \
  V(Float32Equal)                     \
  V(Float32LessThan)                  \
  V(Float32LessThanOrEqual)           \
  V(Float64Equal)                     \
  V(Float64LessThan)                  \
  V(Float64LessThanOrEqual)

#define MACHINE_UNOP_32_LIST(V) \
  V(Word32Clz)                  \
  V(Word32Ctz)                  \
  V(Int32AbsWithOverflow)       \
  V(Word32ReverseBits)          \
  V(Word32ReverseBytes)

#define MACHINE_BINOP_32_LIST(V) \
  V(Word32And)                   \
  V(Word32Or)                    \
  V(Word32Xor)                   \
  V(Word32Shl)                   \
  V(Word32Shr)                   \
  V(Word32Sar)                   \
  V(Word32Rol)                   \
  V(Word32Ror)                   \
  V(Int32Add)                    \
  V(Int32AddWithOverflow)        \
  V(Int32Sub)                    \
  V(Int32SubWithOverflow)        \
  V(Int32Mul)                    \
  V(Int32MulWithOverflow)        \
  V(Int32MulHigh)                \
  V(Int32Div)                    \
  V(Int32Mod)                    \
  V(Uint32Div)                   \
  V(Uint32Mod)                   \
  V(Uint32MulHigh)

#define MACHINE_BINOP_64_LIST(V) \
  V(Word64And)                   \
  V(Word64Or)                    \
  V(Word64Xor)                   \
  V(Word64Shl)                   \
  V(Word64Shr)                   \
  V(Word64Sar)                   \
  V(Word64Rol)                   \
  V(Word64Ror)                   \
  V(Word64RolLowerable)          \
  V(Word64RorLowerable)          \
  V(Int64Add)                    \
  V(Int64AddWithOverflow)        \
  V(Int64Sub)                    \
  V(Int64SubWithOverflow)        \
  V(Int64Mul)                    \
  V(Int64Div)                    \
  V(Int64Mod)                    \
  V(Uint64Div)                   \
  V(Uint64Mod)

#define MACHINE_FLOAT32_UNOP_LIST(V) \
  V(Float32Abs)                      \
  V(Float32Neg)                      \
  V(Float32RoundDown)                \
  V(Float32RoundTiesEven)            \
  V(Float32RoundTruncate)            \
  V(Float32RoundUp)                  \
  V(Float32Sqrt)

#define MACHINE_FLOAT32_BINOP_LIST(V) \
  V(Float32Add)                       \
  V(Float32Sub)                       \
  V(Float32Mul)                       \
  V(Float32Div)                       \
  V(Float32Max)                       \
  V(Float32Min)

#define MACHINE_FLOAT64_UNOP_LIST(V) \
  V(Float64Abs)                      \
  V(Float64Acos)                     \
  V(Float64Acosh)                    \
  V(Float64Asin)                     \
  V(Float64Asinh)                    \
  V(Float64Atan)                     \
  V(Float64Atanh)                    \
  V(Float64Cbrt)                     \
  V(Float64Cos)                      \
  V(Float64Cosh)                     \
  V(Float64Exp)                      \
  V(Float64Expm1)                    \
  V(Float64Log)                      \
  V(Float64Log1p)                    \
  V(Float64Log10)                    \
  V(Float64Log2)                     \
  V(Float64Neg)                      \
  V(Float64RoundDown)                \
  V(Float64RoundTiesAway)            \
  V(Float64RoundTiesEven)            \
  V(Float64RoundTruncate)            \
  V(Float64RoundUp)                  \
  V(Float64Sin)                      \
  V(Float64Sinh)                     \
  V(Float64Sqrt)                     \
  V(Float64Tan)                      \
  V(Float64Tanh)

#define MACHINE_FLOAT64_BINOP_LIST(V) \
  V(Float64Atan2)                     \
  V(Float64Max)                       \
  V(Float64Min)                       \
  V(Float64Add)                       \
  V(Float64Sub)                       \
  V(Float64Mul)                       \
  V(Float64Div)                       \
  V(Float64Mod)                       \
  V(Float64Pow)

#define MACHINE_ATOMIC_OP_LIST(V)    \
  V(Word32AtomicLoad)                \
  V(Word32AtomicStore)               \
  V(Word32AtomicExchange)            \
  V(Word32AtomicCompareExchange)     \
  V(Word32AtomicAdd)                 \
  V(Word32AtomicSub)                 \
  V(Word32AtomicAnd)                 \
  V(Word32AtomicOr)                  \
  V(Word32AtomicXor)                 \
  V(Word32AtomicPairLoad)            \
  V(Word32AtomicPairStore)           \
  V(Word32AtomicPairAdd)             \
  V(Word32AtomicPairSub)             \
  V(Word32AtomicPairAnd)             \
  V(Word32AtomicPairOr)              \
  V(Word32AtomicPairXor)             \
  V(Word32AtomicPairExchange)        \
  V(Word32AtomicPairCompareExchange) \
  V(Word64AtomicLoad)                \
  V(Word64AtomicStore)               \
  V(Word64AtomicAdd)                 \
  V(Word64AtomicSub)                 \
  V(Word64AtomicAnd)                 \
  V(Word64AtomicOr)                  \
  V(Word64AtomicXor)                 \
  V(Word64AtomicExchange)            \
  V(Word64AtomicCompareExchange)

#define MACHINE_OP_LIST(V)               \
  MACHINE_UNOP_32_LIST(V)                \
  MACHINE_BINOP_32_LIST(V)               \
  MACHINE_BINOP_64_LIST(V)               \
  MACHINE_COMPARE_BINOP_LIST(V)          \
  MACHINE_FLOAT32_BINOP_LIST(V)          \
  MACHINE_FLOAT32_UNOP_LIST(V)           \
  MACHINE_FLOAT64_BINOP_LIST(V)          \
  MACHINE_FLOAT64_UNOP_LIST(V)           \
  MACHINE_ATOMIC_OP_LIST(V)              \
  V(AbortCSAAssert)                      \
  V(DebugBreak)                          \
  V(Comment)                             \
  V(Load)                                \
  V(PoisonedLoad)                        \
  V(LoadImmutable)                       \
  V(Store)                               \
  V(StackSlot)                           \
  V(Word32Popcnt)                        \
  V(Word64Popcnt)                        \
  V(Word64Clz)                           \
  V(Word64Ctz)                           \
  V(Word64ClzLowerable)                  \
  V(Word64CtzLowerable)                  \
  V(Word64ReverseBits)                   \
  V(Word64ReverseBytes)                  \
  V(Simd128ReverseBytes)                 \
  V(Int64AbsWithOverflow)                \
  V(BitcastTaggedToWord)                 \
  V(BitcastTaggedToWordForTagAndSmiBits) \
  V(BitcastWordToTagged)                 \
  V(BitcastWordToTaggedSigned)           \
  V(TruncateFloat64ToWord32)             \
  V(ChangeFloat32ToFloat64)              \
  V(ChangeFloat64ToInt32)                \
  V(ChangeFloat64ToInt64)                \
  V(ChangeFloat64ToUint32)               \
  V(ChangeFloat64ToUint64)               \
  V(Float64SilenceNaN)                   \
  V(TruncateFloat64ToInt64)              \
  V(TruncateFloat64ToUint32)             \
  V(TruncateFloat32ToInt32)              \
  V(TruncateFloat32ToUint32)             \
  V(TryTruncateFloat32ToInt64)           \
  V(TryTruncateFloat64ToInt64)           \
  V(TryTruncateFloat32ToUint64)          \
  V(TryTruncateFloat64ToUint64)          \
  V(ChangeInt32ToFloat64)                \
  V(BitcastWord32ToWord64)               \
  V(ChangeInt32ToInt64)                  \
  V(ChangeInt64ToFloat64)                \
  V(ChangeUint32ToFloat64)               \
  V(ChangeUint32ToUint64)                \
  V(TruncateFloat64ToFloat32)            \
  V(TruncateInt64ToInt32)                \
  V(RoundFloat64ToInt32)                 \
  V(RoundInt32ToFloat32)                 \
  V(RoundInt64ToFloat32)                 \
  V(RoundInt64ToFloat64)                 \
  V(RoundUint32ToFloat32)                \
  V(RoundUint64ToFloat32)                \
  V(RoundUint64ToFloat64)                \
  V(BitcastFloat32ToInt32)               \
  V(BitcastFloat64ToInt64)               \
  V(BitcastInt32ToFloat32)               \
  V(BitcastInt64ToFloat64)               \
  V(Float64ExtractLowWord32)             \
  V(Float64ExtractHighWord32)            \
  V(Float64InsertLowWord32)              \
  V(Float64InsertHighWord32)             \
  V(Word32Select)                        \
  V(Word64Select)                        \
  V(Float32Select)                       \
  V(Float64Select)                       \
  V(TaggedPoisonOnSpeculation)           \
  V(Word32PoisonOnSpeculation)           \
  V(Word64PoisonOnSpeculation)           \
  V(LoadStackCheckOffset)                \
  V(LoadFramePointer)                    \
  V(LoadParentFramePointer)              \
  V(UnalignedLoad)                       \
  V(UnalignedStore)                      \
  V(Int32PairAdd)                        \
  V(Int32PairSub)                        \
  V(Int32PairMul)                        \
  V(Word32PairShl)                       \
  V(Word32PairShr)                       \
  V(Word32PairSar)                       \
  V(ProtectedLoad)                       \
  V(ProtectedStore)                      \
  V(MemoryBarrier)                       \
  V(SignExtendWord8ToInt32)              \
  V(SignExtendWord16ToInt32)             \
  V(SignExtendWord8ToInt64)              \
  V(SignExtendWord16ToInt64)             \
  V(SignExtendWord32ToInt64)             \
  V(UnsafePointerAdd)                    \
  V(StackPointerGreaterThan)

#define MACHINE_SIMD_OP_LIST(V) \
  V(F64x2Splat)                 \
  V(F64x2ExtractLane)           \
  V(F64x2ReplaceLane)           \
  V(F64x2Abs)                   \
  V(F64x2Neg)                   \
  V(F64x2Sqrt)                  \
  V(F64x2Add)                   \
  V(F64x2Sub)                   \
  V(F64x2Mul)                   \
  V(F64x2Div)                   \
  V(F64x2Min)                   \
  V(F64x2Max)                   \
  V(F64x2Eq)                    \
  V(F64x2Ne)                    \
  V(F64x2Lt)                    \
  V(F64x2Le)                    \
  V(F64x2Qfma)                  \
  V(F64x2Qfms)                  \
  V(F64x2Pmin)                  \
  V(F64x2Pmax)                  \
  V(F64x2Ceil)                  \
  V(F64x2Floor)                 \
  V(F64x2Trunc)                 \
  V(F64x2NearestInt)            \
  V(F64x2ConvertLowI32x4S)      \
  V(F64x2ConvertLowI32x4U)      \
  V(F64x2PromoteLowF32x4)       \
  V(F32x4Splat)                 \
  V(F32x4ExtractLane)           \
  V(F32x4ReplaceLane)           \
  V(F32x4SConvertI32x4)         \
  V(F32x4UConvertI32x4)         \
  V(F32x4Abs)                   \
  V(F32x4Neg)                   \
  V(F32x4Sqrt)                  \
  V(F32x4RecipApprox)           \
  V(F32x4RecipSqrtApprox)       \
  V(F32x4Add)                   \
  V(F32x4Sub)                   \
  V(F32x4Mul)                   \
  V(F32x4Div)                   \
  V(F32x4Min)                   \
  V(F32x4Max)                   \
  V(F32x4Eq)                    \
  V(F32x4Ne)                    \
  V(F32x4Lt)                    \
  V(F32x4Le)                    \
  V(F32x4Gt)                    \
  V(F32x4Ge)                    \
  V(F32x4Qfma)                  \
  V(F32x4Qfms)                  \
  V(F32x4Pmin)                  \
  V(F32x4Pmax)                  \
  V(F32x4Ceil)                  \
  V(F32x4Floor)                 \
  V(F32x4Trunc)                 \
  V(F32x4NearestInt)            \
  V(F32x4DemoteF64x2Zero)       \
  V(I64x2Splat)                 \
  V(I64x2SplatI32Pair)          \
  V(I64x2ExtractLane)           \
  V(I64x2ReplaceLane)           \
  V(I64x2ReplaceLaneI32Pair)    \
  V(I64x2Abs)                   \
  V(I64x2Neg)                   \
  V(I64x2SConvertI32x4Low)      \
  V(I64x2SConvertI32x4High)     \
  V(I64x2UConvertI32x4Low)      \
  V(I64x2UConvertI32x4High)     \
  V(I64x2BitMask)               \
  V(I64x2Shl)                   \
  V(I64x2ShrS)                  \
  V(I64x2Add)                   \
  V(I64x2Sub)                   \
  V(I64x2Mul)                   \
  V(I64x2Eq)                    \
  V(I64x2Ne)                    \
  V(I64x2GtS)                   \
  V(I64x2GeS)                   \
  V(I64x2ShrU)                  \
  V(I64x2ExtMulLowI32x4S)       \
  V(I64x2ExtMulHighI32x4S)      \
  V(I64x2ExtMulLowI32x4U)       \
  V(I64x2ExtMulHighI32x4U)      \
  V(I32x4Splat)                 \
  V(I32x4ExtractLane)           \
  V(I32x4ReplaceLane)           \
  V(I32x4SConvertF32x4)         \
  V(I32x4SConvertI16x8Low)      \
  V(I32x4SConvertI16x8High)     \
  V(I32x4Neg)                   \
  V(I32x4Shl)                   \
  V(I32x4ShrS)                  \
  V(I32x4Add)                   \
  V(I32x4Sub)                   \
  V(I32x4Mul)                   \
  V(I32x4MinS)                  \
  V(I32x4MaxS)                  \
  V(I32x4Eq)                    \
  V(I32x4Ne)                    \
  V(I32x4LtS)                   \
  V(I32x4LeS)                   \
  V(I32x4GtS)                   \
  V(I32x4GeS)                   \
  V(I32x4UConvertF32x4)         \
  V(I32x4UConvertI16x8Low)      \
  V(I32x4UConvertI16x8High)     \
  V(I32x4ShrU)                  \
  V(I32x4MinU)                  \
  V(I32x4MaxU)                  \
  V(I32x4LtU)                   \
  V(I32x4LeU)                   \
  V(I32x4GtU)                   \
  V(I32x4GeU)                   \
  V(I32x4Abs)                   \
  V(I32x4BitMask)               \
  V(I32x4DotI16x8S)             \
  V(I32x4ExtMulLowI16x8S)       \
  V(I32x4ExtMulHighI16x8S)      \
  V(I32x4ExtMulLowI16x8U)       \
  V(I32x4ExtMulHighI16x8U)      \
  V(I32x4ExtAddPairwiseI16x8S)  \
  V(I32x4ExtAddPairwiseI16x8U)  \
  V(I32x4TruncSatF64x2SZero)    \
  V(I32x4TruncSatF64x2UZero)    \
  V(I16x8Splat)                 \
  V(I16x8ExtractLaneU)          \
  V(I16x8ExtractLaneS)          \
  V(I16x8ReplaceLane)           \
  V(I16x8SConvertI8x16Low)      \
  V(I16x8SConvertI8x16High)     \
  V(I16x8Neg)                   \
  V(I16x8Shl)                   \
  V(I16x8ShrS)                  \
  V(I16x8SConvertI32x4)         \
  V(I16x8Add)                   \
  V(I16x8AddSatS)               \
  V(I16x8Sub)                   \
  V(I16x8SubSatS)               \
  V(I16x8Mul)                   \
  V(I16x8MinS)                  \
  V(I16x8MaxS)                  \
  V(I16x8Eq)                    \
  V(I16x8Ne)                    \
  V(I16x8LtS)                   \
  V(I16x8LeS)                   \
  V(I16x8GtS)                   \
  V(I16x8GeS)                   \
  V(I16x8UConvertI8x16Low)      \
  V(I16x8UConvertI8x16High)     \
  V(I16x8ShrU)                  \
  V(I16x8UConvertI32x4)         \
  V(I16x8AddSatU)               \
  V(I16x8SubSatU)               \
  V(I16x8MinU)                  \
  V(I16x8MaxU)                  \
  V(I16x8LtU)                   \
  V(I16x8LeU)                   \
  V(I16x8GtU)                   \
  V(I16x8GeU)                   \
  V(I16x8RoundingAverageU)      \
  V(I16x8Q15MulRSatS)           \
  V(I16x8Abs)                   \
  V(I16x8BitMask)               \
  V(I16x8ExtMulLowI8x16S)       \
  V(I16x8ExtMulHighI8x16S)      \
  V(I16x8ExtMulLowI8x16U)       \
  V(I16x8ExtMulHighI8x16U)      \
  V(I16x8ExtAddPairwiseI8x16S)  \
  V(I16x8ExtAddPairwiseI8x16U)  \
  V(I8x16Splat)                 \
  V(I8x16ExtractLaneU)          \
  V(I8x16ExtractLaneS)          \
  V(I8x16ReplaceLane)           \
  V(I8x16SConvertI16x8)         \
  V(I8x16Neg)                   \
  V(I8x16Shl)                   \
  V(I8x16ShrS)                  \
  V(I8x16Add)                   \
  V(I8x16AddSatS)               \
  V(I8x16Sub)                   \
  V(I8x16SubSatS)               \
  V(I8x16MinS)                  \
  V(I8x16MaxS)                  \
  V(I8x16Eq)                    \
  V(I8x16Ne)                    \
  V(I8x16LtS)                   \
  V(I8x16LeS)                   \
  V(I8x16GtS)                   \
  V(I8x16GeS)                   \
  V(I8x16UConvertI16x8)         \
  V(I8x16AddSatU)               \
  V(I8x16SubSatU)               \
  V(I8x16ShrU)                  \
  V(I8x16MinU)                  \
  V(I8x16MaxU)                  \
  V(I8x16LtU)                   \
  V(I8x16LeU)                   \
  V(I8x16GtU)                   \
  V(I8x16GeU)                   \
  V(I8x16RoundingAverageU)      \
  V(I8x16Popcnt)                \
  V(I8x16Abs)                   \
  V(I8x16BitMask)               \
  V(S128Zero)                   \
  V(S128Const)                  \
  V(S128Not)                    \
  V(S128And)                    \
  V(S128Or)                     \
  V(S128Xor)                    \
  V(S128Select)                 \
  V(S128AndNot)                 \
  V(I8x16Swizzle)               \
  V(I8x16Shuffle)               \
  V(V128AnyTrue)                \
  V(I64x2AllTrue)               \
  V(I32x4AllTrue)               \
  V(I16x8AllTrue)               \
  V(I8x16AllTrue)               \
  V(LoadTransform)              \
  V(LoadLane)                   \
  V(StoreLane)

#define VALUE_OP_LIST(V)  \
  COMMON_OP_LIST(V)       \
  SIMPLIFIED_OP_LIST(V)   \
  MACHINE_OP_LIST(V)      \
  MACHINE_SIMD_OP_LIST(V) \
  JS_OP_LIST(V)

// The combination of all operators at all levels and the common operators.
#define ALL_OP_LIST(V) \
  CONTROL_OP_LIST(V)   \
  VALUE_OP_LIST(V)


#define CONTROL_OP_LIST_N(V)           \
  V(Start_control)                           \
  V(Loop_control)                            \
  V(Branch_control)                          \
  V(Switch_control)                          \
  V(IfTrue_control)                          \
  V(IfFalse_control)                         \
  V(IfSuccess_control)                       \
  V(IfException_control)                     \
  V(IfValue_control)                         \
  V(IfDefault_control)                       \
  V(Merge_control)                           \
  V(Deoptimize_control)                      \
  V(DeoptimizeIf_control)                    \
  V(DeoptimizeUnless_control)                \
  V(DynamicCheckMapsWithDeoptUnless_control) \
  V(TrapIf_control)                          \
  V(TrapUnless_control)                      \
  V(Return_control)                          \
  V(TailCall_control)                        \
  V(Terminate_control)                       \
  V(Throw_control)                           \
  V(End_control)

// Opcodes for constant operators.
#define CONSTANT_OP_LIST_N(V)   \
  V(Int32Constant_common_constant)            \
  V(Int64Constant_common_constant)            \
  V(TaggedIndexConstant_common_constant)      \
  V(Float32Constant_common_constant)          \
  V(Float64Constant_common_constant)          \
  V(ExternalConstant_common_constant)         \
  V(NumberConstant_common_constant)           \
  V(PointerConstant_common_constant)          \
  V(HeapConstant_common_constant)             \
  V(CompressedHeapConstant_common_constant)   \
  V(RelocatableInt32Constant_common_constant) \
  V(RelocatableInt64Constant_common_constant)

#define INNER_OP_LIST_N(V)    \
  V(Select_common_innner)                 \
  V(Phi_common_innner)                    \
  V(EffectPhi_common_innner)              \
  V(InductionVariablePhi_common_innner)   \
  V(Checkpoint_common_innner)             \
  V(BeginRegion_common_innner)            \
  V(FinishRegion_common_innner)           \
  V(FrameState_common_innner)             \
  V(StateValues_common_innner)            \
  V(TypedStateValues_common_innner)       \
  V(ArgumentsElementsState_common_innner) \
  V(ArgumentsLengthState_common_innner)   \
  V(ObjectState_common_innner)            \
  V(ObjectId_common_innner)               \
  V(TypedObjectState_common_innner)       \
  V(Call_common_innner)                   \
  V(Parameter_common_innner)              \
  V(OsrValue_common_innner)               \
  V(LoopExit_common_innner)               \
  V(LoopExitValue_common_innner)          \
  V(LoopExitEffect_common_innner)         \
  V(Projection_common_innner)             \
  V(Retain_common_innner)                 \
  V(MapGuard_common_innner)               \
  V(FoldConstant_common_innner)           \
  V(TypeGuard_common_innner)

#define COMMON_OP_LIST_N(V) \
  CONSTANT_OP_LIST_N(V)     \
  INNER_OP_LIST_N(V)        \
  V(Unreachable_common_tail)          \
  V(DeadValue_common_tail)            \
  V(Dead_common_tail)                 \
  V(StaticAssert_common_tail)

// Opcodes for JavaScript operators.
// Arguments are JSName (the name with a 'JS' prefix), and Name.
#define JS_COMPARE_BINOP_LIST_N(V)        \
  V(JSEqual_js_compare_binop, Equal)                     \
  V(JSStrictEqual_js_compare_binop, StrictEqual)         \
  V(JSLessThan_js_compare_binop, LessThan)               \
  V(JSGreaterThan_js_compare_binop, GreaterThan)         \
  V(JSLessThanOrEqual_js_compare_binop, LessThanOrEqual) \
  V(JSGreaterThanOrEqual_js_compare_binop, GreaterThanOrEqual)

#define JS_BITWISE_BINOP_LIST_N(V) \
  V(JSBitwiseOr_js_bitwise_binop, BitwiseOr)      \
  V(JSBitwiseXor_js_bitwise_binop, BitwiseXor)    \
  V(JSBitwiseAnd_js_bitwise_binop, BitwiseAnd)    \
  V(JSShiftLeft_js_bitwise_binop, ShiftLeft)      \
  V(JSShiftRight_js_bitwise_binop, ShiftRight)    \
  V(JSShiftRightLogical_js_bitwise_binop, ShiftRightLogical)

#define JS_ARITH_BINOP_LIST_N(V) \
  V(JSAdd_js_arith_binop, Add)                \
  V(JSSubtract_js_arith_binop, Subtract)      \
  V(JSMultiply_js_arith_binop, Multiply)      \
  V(JSDivide_js_arith_binop, Divide)          \
  V(JSModulus_js_arith_binop, Modulus)        \
  V(JSExponentiate_js_arith_binop, Exponentiate)

#define JS_SIMPLE_BINOP_LIST_N(V) \
  JS_COMPARE_BINOP_LIST_N(V)      \
  JS_BITWISE_BINOP_LIST_N(V)      \
  JS_ARITH_BINOP_LIST_N(V)        \
  V(JSHasInPrototypeChain)      \
  V(JSInstanceOf)               \
  V(JSOrdinaryHasInstance)

#define JS_CONVERSION_UNOP_LIST_N(V) \
  V(JSToLength_js_conversion_unop)                    \
  V(JSToName_js_conversion_unop)                      \
  V(JSToNumber_js_conversion_unop)                    \
  V(JSToNumberConvertBigInt_js_conversion_unop)       \
  V(JSToNumeric_js_conversion_unop)                   \
  V(JSToObject_js_conversion_unop)                    \
  V(JSToString_js_conversion_unop)                    \
  V(JSParseInt_js_conversion_unop)

#define JS_BITWISE_UNOP_LIST_N(V) \
  V(JSBitwiseNot_js_bitwise_unop, BitwiseNot)   \
  V(JSNegate_js_bitwise_unop, Negate)

#define JS_ARITH_UNOP_LIST_N(V) \
  V(JSDecrement_js_arith_unop, Decrement)   \
  V(JSIncrement_js_arith_unop, Increment)

#define JS_SIMPLE_UNOP_LIST_N(V) \
  JS_ARITH_UNOP_LIST_N(V)        \
  JS_BITWISE_UNOP_LIST_N(V)      \
  JS_CONVERSION_UNOP_LIST_N(V)

#define JS_CREATE_OP_LIST_N(V)     \
  V(JSCloneObject_js_create_op)               \
  V(JSCreate_js_create_op)                    \
  V(JSCreateArguments_js_create_op)           \
  V(JSCreateArray_js_create_op)               \
  V(JSCreateArrayFromIterable_js_create_op)   \
  V(JSCreateArrayIterator_js_create_op)       \
  V(JSCreateAsyncFunctionObject_js_create_op) \
  V(JSCreateBoundFunction_js_create_op)       \
  V(JSCreateClosure_js_create_op)             \
  V(JSCreateCollectionIterator_js_create_op)  \
  V(JSCreateEmptyLiteralArray_js_create_op)   \
  V(JSCreateEmptyLiteralObject_js_create_op)  \
  V(JSCreateGeneratorObject_js_create_op)     \
  V(JSCreateIterResultObject_js_create_op)    \
  V(JSCreateKeyValueArray_js_create_op)       \
  V(JSCreateLiteralArray_js_create_op)        \
  V(JSCreateLiteralObject_js_create_op)       \
  V(JSCreateLiteralRegExp_js_create_op)       \
  V(JSCreateObject_js_create_op)              \
  V(JSCreatePromise_js_create_op)             \
  V(JSCreateStringIterator_js_create_op)      \
  V(JSCreateTypedArray_js_create_op)          \
  V(JSGetTemplateObject_js_create_op)

#define JS_OBJECT_OP_LIST_N(V)      \
  JS_CREATE_OP_LIST_N(V)            \
  V(JSLoadProperty_js_object_op)               \
  V(JSLoadNamed_js_object_op)                  \
  V(JSLoadNamedFromSuper_js_object_op)         \
  V(JSLoadGlobal_js_object_op)                 \
  V(JSStoreProperty_js_object_op)              \
  V(JSStoreNamed_js_object_op)                 \
  V(JSStoreNamedOwn_js_object_op)              \
  V(JSStoreGlobal_js_object_op)                \
  V(JSStoreDataPropertyInLiteral_js_object_op) \
  V(JSStoreInArrayLiteral_js_object_op)        \
  V(JSDeleteProperty_js_object_op)             \
  V(JSHasProperty_js_object_op)                \
  V(JSGetSuperConstructor_js_object_op)

#define JS_CONTEXT_OP_LIST_N(V) \
  V(JSHasContextExtension_js_context_op)    \
  V(JSLoadContext_js_context_op)            \
  V(JSStoreContext_js_context_op)           \
  V(JSCreateFunctionContext_js_context_op)  \
  V(JSCreateCatchContext_js_context_op)     \
  V(JSCreateWithContext_js_context_op)      \
  V(JSCreateBlockContext_js_context_op)

#define JS_CALL_OP_LIST_N(V) \
  V(JSCall_js_call_op)                \
  V(JSCallForwardVarargs_js_call_op)  \
  V(JSCallWithArrayLike_js_call_op)   \
  V(JSCallWithSpread_js_call_op)      \
  IF_WASM(V, JSWasmCall)

#define JS_CONSTRUCT_OP_LIST_N(V) \
  V(JSConstructForwardVarargs_js_construct_op)  \
  V(JSConstruct_js_construct_op)                \
  V(JSConstructWithArrayLike_js_construct_op)   \
  V(JSConstructWithSpread_js_construct_op)

#define JS_OTHER_OP_LIST_N(V)            \
  JS_CALL_OP_LIST_N(V)                   \
  JS_CONSTRUCT_OP_LIST_N(V)              \
  V(JSAsyncFunctionEnter_js_other_op)              \
  V(JSAsyncFunctionReject_js_other_op)             \
  V(JSAsyncFunctionResolve_js_other_op)            \
  V(JSCallRuntime_js_other_op)                     \
  V(JSForInEnumerate_js_other_op)                  \
  V(JSForInNext_js_other_op)                       \
  V(JSForInPrepare_js_other_op)                    \
  V(JSGetIterator_js_other_op)                     \
  V(JSLoadMessage_js_other_op)                     \
  V(JSStoreMessage_js_other_op)                    \
  V(JSLoadModule_js_other_op)                      \
  V(JSStoreModule_js_other_op)                     \
  V(JSGetImportMeta_js_other_op)                   \
  V(JSGeneratorStore_js_other_op)                  \
  V(JSGeneratorRestoreContinuation_js_other_op)    \
  V(JSGeneratorRestoreContext_js_other_op)         \
  V(JSGeneratorRestoreRegister_js_other_op)        \
  V(JSGeneratorRestoreInputOrDebugPos_js_other_op) \
  V(JSFulfillPromise_js_other_op)                  \
  V(JSPerformPromiseThen_js_other_op)              \
  V(JSPromiseResolve_js_other_op)                  \
  V(JSRejectPromise_js_other_op)                   \
  V(JSResolvePromise_js_other_op)                  \
  V(JSStackCheck_js_other_op)                      \
  V(JSObjectIsArray_js_other_op)                   \
  V(JSRegExpTest_js_other_op)                      \
  V(JSDebugger_js_other_op)

#define JS_OP_LIST_N(V)     \
  JS_SIMPLE_BINOP_LIST_N(V) \
  JS_SIMPLE_UNOP_LIST_N(V)  \
  JS_OBJECT_OP_LIST_N(V)    \
  JS_CONTEXT_OP_LIST_N(V)   \
  JS_OTHER_OP_LIST_N(V)

// Opcodes for VirtuaMachine-level operators.
#define SIMPLIFIED_CHANGE_OP_LIST_N(V) \
  V(ChangeTaggedSignedToInt32_simp_change_op)       \
  V(ChangeTaggedSignedToInt64_simp_change_op)       \
  V(ChangeTaggedToInt32_simp_change_op)             \
  V(ChangeTaggedToInt64_simp_change_op)             \
  V(ChangeTaggedToUint32_simp_change_op)            \
  V(ChangeTaggedToFloat64_simp_change_op)           \
  V(ChangeTaggedToTaggedSigned_simp_change_op)      \
  V(ChangeInt31ToTaggedSigned_simp_change_op)       \
  V(ChangeInt32ToTagged_simp_change_op)             \
  V(ChangeInt64ToTagged_simp_change_op)             \
  V(ChangeUint32ToTagged_simp_change_op)            \
  V(ChangeUint64ToTagged_simp_change_op)            \
  V(ChangeFloat64ToTagged_simp_change_op)           \
  V(ChangeFloat64ToTaggedPointer_simp_change_op)    \
  V(ChangeTaggedToBit_simp_change_op)               \
  V(ChangeBitToTagged_simp_change_op)               \
  V(ChangeUint64ToBigInt_simp_change_op)            \
  V(TruncateBigIntToUint64_simp_change_op)          \
  V(TruncateTaggedToWord32_simp_change_op)          \
  V(TruncateTaggedToFloat64_simp_change_op)         \
  V(TruncateTaggedToBit_simp_change_op)             \
  V(TruncateTaggedPointerToBit_simp_change_op)

#define SIMPLIFIED_CHECKED_OP_LIST_N(V) \
  V(CheckedInt32Add_simp_checked_op)                  \
  V(CheckedInt32Sub_simp_checked_op)                  \
  V(CheckedInt32Div_simp_checked_op)                  \
  V(CheckedInt32Mod_simp_checked_op)                  \
  V(CheckedUint32Div_simp_checked_op)                 \
  V(CheckedUint32Mod_simp_checked_op)                 \
  V(CheckedInt32Mul_simp_checked_op)                  \
  V(CheckedInt32ToTaggedSigned_simp_checked_op)       \
  V(CheckedInt64ToInt32_simp_checked_op)              \
  V(CheckedInt64ToTaggedSigned_simp_checked_op)       \
  V(CheckedUint32Bounds_simp_checked_op)              \
  V(CheckedUint32ToInt32_simp_checked_op)             \
  V(CheckedUint32ToTaggedSigned_simp_checked_op)      \
  V(CheckedUint64Bounds_simp_checked_op)              \
  V(CheckedUint64ToInt32_simp_checked_op)             \
  V(CheckedUint64ToTaggedSigned_simp_checked_op)      \
  V(CheckedFloat64ToInt32_simp_checked_op)            \
  V(CheckedFloat64ToInt64_simp_checked_op)            \
  V(CheckedTaggedSignedToInt32_simp_checked_op)       \
  V(CheckedTaggedToInt32_simp_checked_op)             \
  V(CheckedTaggedToArrayIndex_simp_checked_op)        \
  V(CheckedTruncateTaggedToWord32_simp_checked_op)    \
  V(CheckedTaggedToFloat64_simp_checked_op)           \
  V(CheckedTaggedToInt64_simp_checked_op)             \
  V(CheckedTaggedToTaggedSigned_simp_checked_op)      \
  V(CheckedTaggedToTaggedPointer_simp_checked_op)

#define SIMPLIFIED_COMPARE_BINOP_LIST_N(V) \
  V(NumberEqual_simp_compare_binop)                         \
  V(NumberLessThan_simp_compare_binop)                      \
  V(NumberLessThanOrEqual_simp_compare_binop)               \
  V(SpeculativeNumberEqual_simp_compare_binop)              \
  V(SpeculativeNumberLessThan_simp_compare_binop)           \
  V(SpeculativeNumberLessThanOrEqual_simp_compare_binop)    \
  V(ReferenceEqual_simp_compare_binop)                      \
  V(SameValue_simp_compare_binop)                           \
  V(SameValueNumbersOnly_simp_compare_binop)                \
  V(NumberSameValue_simp_compare_binop)                     \
  V(StringEqual_simp_compare_binop)                         \
  V(StringLessThan_simp_compare_binop)                      \
  V(StringLessThanOrEqual_simp_compare_binop)

#define SIMPLIFIED_NUMBER_BINOP_LIST_N(V) \
  V(NumberAdd_simp_number_binop)                          \
  V(NumberSubtract_simp_number_binop)                     \
  V(NumberMultiply_simp_number_binop)                     \
  V(NumberDivide_simp_number_binop)                       \
  V(NumberModulus_simp_number_binop)                      \
  V(NumberBitwiseOr_simp_number_binop)                    \
  V(NumberBitwiseXor_simp_number_binop)                   \
  V(NumberBitwiseAnd_simp_number_binop)                   \
  V(NumberShiftLeft_simp_number_binop)                    \
  V(NumberShiftRight_simp_number_binop)                   \
  V(NumberShiftRightLogical_simp_number_binop)            \
  V(NumberAtan2_simp_number_binop)                        \
  V(NumberImul_simp_number_binop)                         \
  V(NumberMax_simp_number_binop)                          \
  V(NumberMin_simp_number_binop)                          \
  V(NumberPow_simp_number_binop)

#define SIMPLIFIED_BIGINT_BINOP_LIST_N(V) \
  V(BigIntAdd_simp_bigint_binop)                          \
  V(BigIntSubtract_simp_bigint_binop)

#define SIMPLIFIED_SPECULATIVE_NUMBER_BINOP_LIST_N(V) \
  V(SpeculativeNumberAdd_simp_speculative_number_binop)                           \
  V(SpeculativeNumberSubtract_simp_speculative_number_binop)                      \
  V(SpeculativeNumberMultiply_simp_speculative_number_binop)                      \
  V(SpeculativeNumberPow_simp_speculative_number_binop)                           \
  V(SpeculativeNumberDivide_simp_speculative_number_binop)                        \
  V(SpeculativeNumberModulus_simp_speculative_number_binop)                       \
  V(SpeculativeNumberBitwiseAnd_simp_speculative_number_binop)                    \
  V(SpeculativeNumberBitwiseOr_simp_speculative_number_binop)                     \
  V(SpeculativeNumberBitwiseXor_simp_speculative_number_binop)                    \
  V(SpeculativeNumberShiftLeft_simp_speculative_number_binop)                     \
  V(SpeculativeNumberShiftRight_simp_speculative_number_binop)                    \
  V(SpeculativeNumberShiftRightLogical_simp_speculative_number_binop)             \
  V(SpeculativeSafeIntegerAdd_simp_speculative_number_binop)                      \
  V(SpeculativeSafeIntegerSubtract_simp_speculative_number_binop)

#define SIMPLIFIED_NUMBER_UNOP_LIST_N(V) \
  V(NumberAbs_simp_number_unop)                         \
  V(NumberAcos_simp_number_unop)                        \
  V(NumberAcosh_simp_number_unop)                       \
  V(NumberAsin_simp_number_unop)                        \
  V(NumberAsinh_simp_number_unop)                       \
  V(NumberAtan_simp_number_unop)                        \
  V(NumberAtanh_simp_number_unop)                       \
  V(NumberCbrt_simp_number_unop)                        \
  V(NumberCeil_simp_number_unop)                        \
  V(NumberClz32_simp_number_unop)                       \
  V(NumberCos_simp_number_unop)                         \
  V(NumberCosh_simp_number_unop)                        \
  V(NumberExp_simp_number_unop)                         \
  V(NumberExpm1_simp_number_unop)                       \
  V(NumberFloor_simp_number_unop)                       \
  V(NumberFround_simp_number_unop)                      \
  V(NumberLog_simp_number_unop)                         \
  V(NumberLog1p_simp_number_unop)                       \
  V(NumberLog2_simp_number_unop)                        \
  V(NumberLog10_simp_number_unop)                       \
  V(NumberRound_simp_number_unop)                       \
  V(NumberSign_simp_number_unop)                        \
  V(NumberSin_simp_number_unop)                         \
  V(NumberSinh_simp_number_unop)                        \
  V(NumberSqrt_simp_number_unop)                        \
  V(NumberTan_simp_number_unop)                         \
  V(NumberTanh_simp_number_unop)                        \
  V(NumberTrunc_simp_number_unop)                       \
  V(NumberToBoolean_simp_number_unop)                   \
  V(NumberToInt32_simp_number_unop)                     \
  V(NumberToString_simp_number_unop)                    \
  V(NumberToUint32_simp_number_unop)                    \
  V(NumberToUint8Clamped_simp_number_unop)              \
  V(NumberSilenceNaN_simp_number_unop)

#define SIMPLIFIED_BIGINT_UNOP_LIST_N(V) \
  V(BigIntNegate_simp_bigint_unop)                      \
  V(CheckBigInt_simp_bigint_unop)

#define SIMPLIFIED_SPECULATIVE_NUMBER_UNOP_LIST_N(V) V(SpeculativeToNumber_simp_specula_number_unop)

#define SIMPLIFIED_OTHER_OP_LIST_N(V)     \
  V(Allocatesimp_other_op)                           \
  V(AllocateRawsimp_other_op)                        \
  V(ArgumentsLengthsimp_other_op)                    \
  V(AssertTypesimp_other_op)                         \
  V(BooleanNotsimp_other_op)                         \
  V(CheckBoundssimp_other_op)                        \
  V(CheckClosuresimp_other_op)                       \
  V(CheckEqualsInternalizedStringsimp_other_op)      \
  V(CheckEqualsSymbolsimp_other_op)                  \
  V(CheckFloat64Holesimp_other_op)                   \
  V(CheckHeapObjectsimp_other_op)                    \
  V(CheckIfsimp_other_op)                            \
  V(CheckInternalizedStringsimp_other_op)            \
  V(CheckMapssimp_other_op)                          \
  V(CheckNotTaggedHolesimp_other_op)                 \
  V(CheckNumbersimp_other_op)                        \
  V(CheckReceiversimp_other_op)                      \
  V(CheckReceiverOrNullOrUndefinedsimp_other_op)     \
  V(CheckSmisimp_other_op)                           \
  V(CheckStringsimp_other_op)                        \
  V(CheckSymbolsimp_other_op)                        \
  V(CompareMapssimp_other_op)                        \
  V(ConvertReceiversimp_other_op)                    \
  V(ConvertTaggedHoleToUndefinedsimp_other_op)       \
  V(DateNowsimp_other_op)                            \
  V(DelayedStringConstantsimp_other_op)              \
  V(DynamicCheckMapssimp_other_op)                   \
  V(EnsureWritableFastElementssimp_other_op)         \
  V(FastApiCallsimp_other_op)                        \
  V(FindOrderedHashMapEntrysimp_other_op)            \
  V(FindOrderedHashMapEntryForInt32Keysimp_other_op) \
  V(LoadDataViewElementsimp_other_op)                \
  V(LoadElementsimp_other_op)                        \
  V(LoadFieldsimp_other_op)                          \
  V(LoadFieldByIndexsimp_other_op)                   \
  V(LoadFromObjectsimp_other_op)                     \
  V(LoadMessagesimp_other_op)                        \
  V(LoadStackArgumentsimp_other_op)                  \
  V(LoadTypedElementsimp_other_op)                   \
  V(MaybeGrowFastElementssimp_other_op)              \
  V(NewArgumentsElementssimp_other_op)               \
  V(NewConsStringsimp_other_op)                      \
  V(NewDoubleElementssimp_other_op)                  \
  V(NewSmiOrObjectElementssimp_other_op)             \
  V(NumberIsFinitesimp_other_op)                     \
  V(NumberIsFloat64Holesimp_other_op)                \
  V(NumberIsIntegersimp_other_op)                    \
  V(NumberIsMinusZerosimp_other_op)                  \
  V(NumberIsNaNsimp_other_op)                        \
  V(NumberIsSafeIntegersimp_other_op)                \
  V(ObjectIsArrayBufferViewsimp_other_op)            \
  V(ObjectIsBigIntsimp_other_op)                     \
  V(ObjectIsCallablesimp_other_op)                   \
  V(ObjectIsConstructorsimp_other_op)                \
  V(ObjectIsDetectableCallablesimp_other_op)         \
  V(ObjectIsFiniteNumbersimp_other_op)               \
  V(ObjectIsIntegersimp_other_op)                    \
  V(ObjectIsMinusZerosimp_other_op)                  \
  V(ObjectIsNaNsimp_other_op)                        \
  V(ObjectIsNonCallablesimp_other_op)                \
  V(ObjectIsNumbersimp_other_op)                     \
  V(ObjectIsReceiversimp_other_op)                   \
  V(ObjectIsSafeIntegersimp_other_op)                \
  V(ObjectIsSmisimp_other_op)                        \
  V(ObjectIsStringsimp_other_op)                     \
  V(ObjectIsSymbolsimp_other_op)                     \
  V(ObjectIsUndetectablesimp_other_op)               \
  V(PlainPrimitiveToFloat64simp_other_op)            \
  V(PlainPrimitiveToNumbersimp_other_op)             \
  V(PlainPrimitiveToWord32simp_other_op)             \
  V(PoisonIndexsimp_other_op)                        \
  V(RestLengthsimp_other_op)                         \
  V(RuntimeAbortsimp_other_op)                       \
  V(StoreDataViewElementsimp_other_op)               \
  V(StoreElementsimp_other_op)                       \
  V(StoreFieldsimp_other_op)                         \
  V(StoreMessagesimp_other_op)                       \
  V(StoreSignedSmallElementsimp_other_op)            \
  V(StoreToObjectsimp_other_op)                      \
  V(StoreTypedElementsimp_other_op)                  \
  V(StringCharCodeAtsimp_other_op)                   \
  V(StringCodePointAtsimp_other_op)                  \
  V(StringConcatsimp_other_op)                       \
  V(StringFromCodePointAtsimp_other_op)              \
  V(StringFromSingleCharCodesimp_other_op)           \
  V(StringFromSingleCodePointsimp_other_op)          \
  V(StringIndexOfsimp_other_op)                      \
  V(StringLengthsimp_other_op)                       \
  V(StringSubstringsimp_other_op)                    \
  V(StringToLowerCaseIntlsimp_other_op)              \
  V(StringToNumbersimp_other_op)                     \
  V(StringToUpperCaseIntlsimp_other_op)              \
  V(TierUpChecksimp_other_op)                        \
  V(ToBooleansimp_other_op)                          \
  V(TransitionAndStoreElementsimp_other_op)          \
  V(TransitionAndStoreNonNumberElementsimp_other_op) \
  V(TransitionAndStoreNumberElementsimp_other_op)    \
  V(TransitionElementsKindsimp_other_op)             \
  V(TypeOfsimp_other_op)                             \
  V(UpdateInterruptBudgetsimp_other_op)              \
  V(VerifyTypesimp_other_op)

#define SIMPLIFIED_SPECULATIVE_BIGINT_BINOP_LIST_N(V) \
  V(SpeculativeBigIntAdd_simp_spec_bigint_binop)                           \
  V(SpeculativeBigIntSubtract_simp_spec_bigint_binop)

#define SIMPLIFIED_SPECULATIVE_BIGINT_UNOP_LIST_N(V) \
  V(SpeculativeBigIntAsUintN_simp_spec_bigint_unop)                      \
  V(SpeculativeBigIntNegate_simp_spec_bigint_unop)

#define SIMPLIFIED_OP_LIST_N(V)                 \
  SIMPLIFIED_CHANGE_OP_LIST_N(V)                \
  SIMPLIFIED_CHECKED_OP_LIST_N(V)               \
  SIMPLIFIED_COMPARE_BINOP_LIST_N(V)            \
  SIMPLIFIED_NUMBER_BINOP_LIST_N(V)             \
  SIMPLIFIED_BIGINT_BINOP_LIST_N(V)             \
  SIMPLIFIED_SPECULATIVE_NUMBER_BINOP_LIST_N(V) \
  SIMPLIFIED_NUMBER_UNOP_LIST_N(V)              \
  SIMPLIFIED_BIGINT_UNOP_LIST_N(V)              \
  SIMPLIFIED_SPECULATIVE_NUMBER_UNOP_LIST_N(V)  \
  SIMPLIFIED_SPECULATIVE_BIGINT_UNOP_LIST_N(V)  \
  SIMPLIFIED_SPECULATIVE_BIGINT_BINOP_LIST_N(V) \
  SIMPLIFIED_OTHER_OP_LIST_N(V)

// Opcodes for Machine-level operators.
#define MACHINE_COMPARE_BINOP_LIST_N(V) \
  V(Word32Equal_mach_compare_binop)                      \
  V(Word64Equal_mach_compare_binop)                      \
  V(Int32LessThan_mach_compare_binop)                    \
  V(Int32LessThanOrEqual_mach_compare_binop)             \
  V(Uint32LessThan_mach_compare_binop)                   \
  V(Uint32LessThanOrEqual_mach_compare_binop)            \
  V(Int64LessThan_mach_compare_binop)                    \
  V(Int64LessThanOrEqual_mach_compare_binop)             \
  V(Uint64LessThan_mach_compare_binop)                   \
  V(Uint64LessThanOrEqual_mach_compare_binop)            \
  V(Float32Equal_mach_compare_binop)                     \
  V(Float32LessThan_mach_compare_binop)                  \
  V(Float32LessThanOrEqual_mach_compare_binop)           \
  V(Float64Equal_mach_compare_binop)                     \
  V(Float64LessThan_mach_compare_binop)                  \
  V(Float64LessThanOrEqual_mach_compare_binop)

#define MACHINE_UNOP_32_LIST_N(V) \
  V(Word32Clz_mach_unop32)                  \
  V(Word32Ctz_mach_unop32)                  \
  V(Int32AbsWithOverflow_mach_unop32)       \
  V(Word32ReverseBits_mach_unop32)          \
  V(Word32ReverseBytes_mach_unop32)

#define MACHINE_BINOP_32_LIST_N(V) \
  V(Word32And_mach_binop32)                   \
  V(Word32Or_mach_binop32)                    \
  V(Word32Xor_mach_binop32)                   \
  V(Word32Shl_mach_binop32)                   \
  V(Word32Shr_mach_binop32)                   \
  V(Word32Sar_mach_binop32)                   \
  V(Word32Rol_mach_binop32)                   \
  V(Word32Ror_mach_binop32)                   \
  V(Int32Add_mach_binop32)                    \
  V(Int32AddWithOverflow_mach_binop32)        \
  V(Int32Sub_mach_binop32)                    \
  V(Int32SubWithOverflow_mach_binop32)        \
  V(Int32Mul_mach_binop32)                    \
  V(Int32MulWithOverflow_mach_binop32)        \
  V(Int32MulHigh_mach_binop32)                \
  V(Int32Div_mach_binop32)                    \
  V(Int32Mod_mach_binop32)                    \
  V(Uint32Div_mach_binop32)                   \
  V(Uint32Mod_mach_binop32)                   \
  V(Uint32MulHigh_mach_binop32)

#define MACHINE_BINOP_64_LIST_N(V) \
  V(Word64And_mach_binop64)                   \
  V(Word64Or_mach_binop64)                    \
  V(Word64Xor_mach_binop64)                   \
  V(Word64Shl_mach_binop64)                   \
  V(Word64Shr_mach_binop64)                   \
  V(Word64Sar_mach_binop64)                   \
  V(Word64Rol_mach_binop64)                   \
  V(Word64Ror_mach_binop64)                   \
  V(Word64RolLowerable_mach_binop64)          \
  V(Word64RorLowerable_mach_binop64)          \
  V(Int64Add_mach_binop64)                    \
  V(Int64AddWithOverflow_mach_binop64)        \
  V(Int64Sub_mach_binop64)                    \
  V(Int64SubWithOverflow_mach_binop64)        \
  V(Int64Mul_mach_binop64)                    \
  V(Int64Div_mach_binop64)                    \
  V(Int64Mod_mach_binop64)                    \
  V(Uint64Div_mach_binop64)                   \
  V(Uint64Mod_mach_binop64)

#define MACHINE_FLOAT32_UNOP_LIST_N(V) \
  V(Float32Abs_mach_unop_fp32)                      \
  V(Float32Neg_mach_unop_fp32)                      \
  V(Float32RoundDown_mach_unop_fp32)                \
  V(Float32RoundTiesEven_mach_unop_fp32)            \
  V(Float32RoundTruncate_mach_unop_fp32)            \
  V(Float32RoundUp_mach_unop_fp32)                  \
  V(Float32Sqrt_mach_unop_fp32)

#define MACHINE_FLOAT32_BINOP_LIST_N(V) \
  V(Float32Add_mach_binop_fp32)                       \
  V(Float32Sub_mach_binop_fp32)                       \
  V(Float32Mul_mach_binop_fp32)                       \
  V(Float32Div_mach_binop_fp32)                       \
  V(Float32Max_mach_binop_fp32)                       \
  V(Float32Min_mach_binop_fp32)

#define MACHINE_FLOAT64_UNOP_LIST_N(V) \
  V(Float64Abs_mach_unop_fp64)                      \
  V(Float64Acos_mach_unop_fp64)                     \
  V(Float64Acosh_mach_unop_fp64)                    \
  V(Float64Asin_mach_unop_fp64)                     \
  V(Float64Asinh_mach_unop_fp64)                    \
  V(Float64Atan_mach_unop_fp64)                     \
  V(Float64Atanh_mach_unop_fp64)                    \
  V(Float64Cbrt_mach_unop_fp64)                     \
  V(Float64Cos_mach_unop_fp64)                      \
  V(Float64Cosh_mach_unop_fp64)                     \
  V(Float64Exp_mach_unop_fp64)                      \
  V(Float64Expm1_mach_unop_fp64)                    \
  V(Float64Log_mach_unop_fp64)                      \
  V(Float64Log1p_mach_unop_fp64)                    \
  V(Float64Log10_mach_unop_fp64)                    \
  V(Float64Log2_mach_unop_fp64)                     \
  V(Float64Neg_mach_unop_fp64)                      \
  V(Float64RoundDown_mach_unop_fp64)                \
  V(Float64RoundTiesAway_mach_unop_fp64)            \
  V(Float64RoundTiesEven_mach_unop_fp64)            \
  V(Float64RoundTruncate_mach_unop_fp64)            \
  V(Float64RoundUp_mach_unop_fp64)                  \
  V(Float64Sin_mach_unop_fp64)                      \
  V(Float64Sinh_mach_unop_fp64)                     \
  V(Float64Sqrt_mach_unop_fp64)                     \
  V(Float64Tan_mach_unop_fp64)                      \
  V(Float64Tanh_mach_unop_fp64)

#define MACHINE_FLOAT64_BINOP_LIST_N(V) \
  V(Float64Atan2_mach_binop_fp64)                     \
  V(Float64Max_mach_binop_fp64)                       \
  V(Float64Min_mach_binop_fp64)                       \
  V(Float64Add_mach_binop_fp64)                       \
  V(Float64Sub_mach_binop_fp64)                       \
  V(Float64Mul_mach_binop_fp64)                       \
  V(Float64Div_mach_binop_fp64)                       \
  V(Float64Mod_mach_binop_fp64)                       \
  V(Float64Pow_mach_binop_fp64)

#define MACHINE_ATOMIC_OP_LIST_N(V)    \
  V(Word32AtomicLoad_mach_atomic_op)                \
  V(Word32AtomicStore_mach_atomic_op)               \
  V(Word32AtomicExchange_mach_atomic_op)            \
  V(Word32AtomicCompareExchange_mach_atomic_op)     \
  V(Word32AtomicAdd_mach_atomic_op)                 \
  V(Word32AtomicSub_mach_atomic_op)                 \
  V(Word32AtomicAnd_mach_atomic_op)                 \
  V(Word32AtomicOr_mach_atomic_op)                  \
  V(Word32AtomicXor_mach_atomic_op)                 \
  V(Word32AtomicPairLoad_mach_atomic_op)            \
  V(Word32AtomicPairStore_mach_atomic_op)           \
  V(Word32AtomicPairAdd_mach_atomic_op)             \
  V(Word32AtomicPairSub_mach_atomic_op)             \
  V(Word32AtomicPairAnd_mach_atomic_op)             \
  V(Word32AtomicPairOr_mach_atomic_op)              \
  V(Word32AtomicPairXor_mach_atomic_op)             \
  V(Word32AtomicPairExchange_mach_atomic_op)        \
  V(Word32AtomicPairCompareExchange_mach_atomic_op) \
  V(Word64AtomicLoad_mach_atomic_op)                \
  V(Word64AtomicStore_mach_atomic_op)               \
  V(Word64AtomicAdd_mach_atomic_op)                 \
  V(Word64AtomicSub_mach_atomic_op)                 \
  V(Word64AtomicAnd_mach_atomic_op)                 \
  V(Word64AtomicOr_mach_atomic_op)                  \
  V(Word64AtomicXor_mach_atomic_op)                 \
  V(Word64AtomicExchange_mach_atomic_op)            \
  V(Word64AtomicCompareExchange_mach_atomic_op)

#define MACHINE_OP_LIST_N(V)               \
  MACHINE_UNOP_32_LIST_N(V)                \
  MACHINE_BINOP_32_LIST_N(V)               \
  MACHINE_BINOP_64_LIST_N(V)               \
  MACHINE_COMPARE_BINOP_LIST_N(V)          \
  MACHINE_FLOAT32_BINOP_LIST_N(V)          \
  MACHINE_FLOAT32_UNOP_LIST_N(V)           \
  MACHINE_FLOAT64_BINOP_LIST_N(V)          \
  MACHINE_FLOAT64_UNOP_LIST_N(V)           \
  MACHINE_ATOMIC_OP_LIST_N(V)              \
  V(AbortCSAAssert_mach_tail_op)                      \
  V(DebugBreak_mach_tail_op)                          \
  V(Comment_mach_tail_op)                             \
  V(Load_mach_tail_op)                                \
  V(PoisonedLoad_mach_tail_op)                        \
  V(LoadImmutable_mach_tail_op)                       \
  V(Store_mach_tail_op)                               \
  V(StackSlot_mach_tail_op)                           \
  V(Word32Popcnt_mach_tail_op)                        \
  V(Word64Popcnt_mach_tail_op)                        \
  V(Word64Clz_mach_tail_op)                           \
  V(Word64Ctz_mach_tail_op)                           \
  V(Word64ClzLowerable_mach_tail_op)                  \
  V(Word64CtzLowerable_mach_tail_op)                  \
  V(Word64ReverseBits_mach_tail_op)                   \
  V(Word64ReverseBytes_mach_tail_op)                  \
  V(Simd128ReverseBytes_mach_tail_op)                 \
  V(Int64AbsWithOverflow_mach_tail_op)                \
  V(BitcastTaggedToWord_mach_tail_op)                 \
  V(BitcastTaggedToWordForTagAndSmiBits_mach_tail_op) \
  V(BitcastWordToTagged_mach_tail_op)                 \
  V(BitcastWordToTaggedSigned_mach_tail_op)           \
  V(TruncateFloat64ToWord32_mach_tail_op)             \
  V(ChangeFloat32ToFloat64_mach_tail_op)              \
  V(ChangeFloat64ToInt32_mach_tail_op)                \
  V(ChangeFloat64ToInt64_mach_tail_op)                \
  V(ChangeFloat64ToUint32_mach_tail_op)               \
  V(ChangeFloat64ToUint64_mach_tail_op)               \
  V(Float64SilenceNaN_mach_tail_op)                   \
  V(TruncateFloat64ToInt64_mach_tail_op)              \
  V(TruncateFloat64ToUint32_mach_tail_op)             \
  V(TruncateFloat32ToInt32_mach_tail_op)              \
  V(TruncateFloat32ToUint32_mach_tail_op)             \
  V(TryTruncateFloat32ToInt64_mach_tail_op)           \
  V(TryTruncateFloat64ToInt64_mach_tail_op)           \
  V(TryTruncateFloat32ToUint64_mach_tail_op)          \
  V(TryTruncateFloat64ToUint64_mach_tail_op)          \
  V(ChangeInt32ToFloat64_mach_tail_op)                \
  V(BitcastWord32ToWord64_mach_tail_op)               \
  V(ChangeInt32ToInt64_mach_tail_op)                  \
  V(ChangeInt64ToFloat64_mach_tail_op)                \
  V(ChangeUint32ToFloat64_mach_tail_op)               \
  V(ChangeUint32ToUint64_mach_tail_op)                \
  V(TruncateFloat64ToFloat32_mach_tail_op)            \
  V(TruncateInt64ToInt32_mach_tail_op)                \
  V(RoundFloat64ToInt32_mach_tail_op)                 \
  V(RoundInt32ToFloat32_mach_tail_op)                 \
  V(RoundInt64ToFloat32_mach_tail_op)                 \
  V(RoundInt64ToFloat64_mach_tail_op)                 \
  V(RoundUint32ToFloat32_mach_tail_op)                \
  V(RoundUint64ToFloat32_mach_tail_op)                \
  V(RoundUint64ToFloat64_mach_tail_op)                \
  V(BitcastFloat32ToInt32_mach_tail_op)               \
  V(BitcastFloat64ToInt64_mach_tail_op)               \
  V(BitcastInt32ToFloat32_mach_tail_op)               \
  V(BitcastInt64ToFloat64_mach_tail_op)               \
  V(Float64ExtractLowWord32_mach_tail_op)             \
  V(Float64ExtractHighWord32_mach_tail_op)            \
  V(Float64InsertLowWord32_mach_tail_op)              \
  V(Float64InsertHighWord32_mach_tail_op)             \
  V(Word32Select_mach_tail_op)                        \
  V(Word64Select_mach_tail_op)                        \
  V(Float32Select_mach_tail_op)                       \
  V(Float64Select_mach_tail_op)                       \
  V(TaggedPoisonOnSpeculation_mach_tail_op)           \
  V(Word32PoisonOnSpeculation_mach_tail_op)           \
  V(Word64PoisonOnSpeculation_mach_tail_op)           \
  V(LoadStackCheckOffset_mach_tail_op)                \
  V(LoadFramePointer_mach_tail_op)                    \
  V(LoadParentFramePointer_mach_tail_op)              \
  V(UnalignedLoad_mach_tail_op)                       \
  V(UnalignedStore_mach_tail_op)                      \
  V(Int32PairAdd_mach_tail_op)                        \
  V(Int32PairSub_mach_tail_op)                        \
  V(Int32PairMul_mach_tail_op)                        \
  V(Word32PairShl_mach_tail_op)                       \
  V(Word32PairShr_mach_tail_op)                       \
  V(Word32PairSar_mach_tail_op)                       \
  V(ProtectedLoad_mach_tail_op)                       \
  V(ProtectedStore_mach_tail_op)                      \
  V(MemoryBarrier_mach_tail_op)                       \
  V(SignExtendWord8ToInt32_mach_tail_op)              \
  V(SignExtendWord16ToInt32_mach_tail_op)             \
  V(SignExtendWord8ToInt64_mach_tail_op)              \
  V(SignExtendWord16ToInt64_mach_tail_op)             \
  V(SignExtendWord32ToInt64_mach_tail_op)             \
  V(UnsafePointerAdd_mach_tail_op)                    \
  V(StackPointerGreaterThan_mach_tail_op)

#define MACHINE_SIMD_OP_LIST_N(V) \
  V(F64x2Splat_mach_simd_op)                 \
  V(F64x2ExtractLane_mach_simd_op)           \
  V(F64x2ReplaceLane_mach_simd_op)           \
  V(F64x2Abs_mach_simd_op)                   \
  V(F64x2Neg_mach_simd_op)                   \
  V(F64x2Sqrt_mach_simd_op)                  \
  V(F64x2Add_mach_simd_op)                   \
  V(F64x2Sub_mach_simd_op)                   \
  V(F64x2Mul_mach_simd_op)                   \
  V(F64x2Div_mach_simd_op)                   \
  V(F64x2Min_mach_simd_op)                   \
  V(F64x2Max_mach_simd_op)                   \
  V(F64x2Eq_mach_simd_op)                    \
  V(F64x2Ne_mach_simd_op)                    \
  V(F64x2Lt_mach_simd_op)                    \
  V(F64x2Le_mach_simd_op)                    \
  V(F64x2Qfma_mach_simd_op)                  \
  V(F64x2Qfms_mach_simd_op)                  \
  V(F64x2Pmin_mach_simd_op)                  \
  V(F64x2Pmax_mach_simd_op)                  \
  V(F64x2Ceil_mach_simd_op)                  \
  V(F64x2Floor_mach_simd_op)                 \
  V(F64x2Trunc_mach_simd_op)                 \
  V(F64x2NearestInt_mach_simd_op)            \
  V(F64x2ConvertLowI32x4S_mach_simd_op)      \
  V(F64x2ConvertLowI32x4U_mach_simd_op)      \
  V(F64x2PromoteLowF32x4_mach_simd_op)       \
  V(F32x4Splat_mach_simd_op)                 \
  V(F32x4ExtractLane_mach_simd_op)           \
  V(F32x4ReplaceLane_mach_simd_op)           \
  V(F32x4SConvertI32x4_mach_simd_op)         \
  V(F32x4UConvertI32x4_mach_simd_op)         \
  V(F32x4Abs_mach_simd_op)                   \
  V(F32x4Neg_mach_simd_op)                   \
  V(F32x4Sqrt_mach_simd_op)                  \
  V(F32x4RecipApprox_mach_simd_op)           \
  V(F32x4RecipSqrtApprox_mach_simd_op)       \
  V(F32x4Add_mach_simd_op)                   \
  V(F32x4Sub_mach_simd_op)                   \
  V(F32x4Mul_mach_simd_op)                   \
  V(F32x4Div_mach_simd_op)                   \
  V(F32x4Min_mach_simd_op)                   \
  V(F32x4Max_mach_simd_op)                   \
  V(F32x4Eq_mach_simd_op)                    \
  V(F32x4Ne_mach_simd_op)                    \
  V(F32x4Lt_mach_simd_op)                    \
  V(F32x4Le_mach_simd_op)                    \
  V(F32x4Gt_mach_simd_op)                    \
  V(F32x4Ge_mach_simd_op)                    \
  V(F32x4Qfma_mach_simd_op)                  \
  V(F32x4Qfms_mach_simd_op)                  \
  V(F32x4Pmin_mach_simd_op)                  \
  V(F32x4Pmax_mach_simd_op)                  \
  V(F32x4Ceil_mach_simd_op)                  \
  V(F32x4Floor_mach_simd_op)                 \
  V(F32x4Trunc_mach_simd_op)                 \
  V(F32x4NearestInt_mach_simd_op)            \
  V(F32x4DemoteF64x2Zero_mach_simd_op)       \
  V(I64x2Splat_mach_simd_op)                 \
  V(I64x2SplatI32Pair_mach_simd_op)          \
  V(I64x2ExtractLane_mach_simd_op)           \
  V(I64x2ReplaceLane_mach_simd_op)           \
  V(I64x2ReplaceLaneI32Pair_mach_simd_op)    \
  V(I64x2Abs_mach_simd_op)                   \
  V(I64x2Neg_mach_simd_op)                   \
  V(I64x2SConvertI32x4Low_mach_simd_op)      \
  V(I64x2SConvertI32x4High_mach_simd_op)     \
  V(I64x2UConvertI32x4Low_mach_simd_op)      \
  V(I64x2UConvertI32x4High_mach_simd_op)     \
  V(I64x2BitMask_mach_simd_op)               \
  V(I64x2Shl_mach_simd_op)                   \
  V(I64x2ShrS_mach_simd_op)                  \
  V(I64x2Add_mach_simd_op)                   \
  V(I64x2Sub_mach_simd_op)                   \
  V(I64x2Mul_mach_simd_op)                   \
  V(I64x2Eq_mach_simd_op)                    \
  V(I64x2Ne_mach_simd_op)                    \
  V(I64x2GtS_mach_simd_op)                   \
  V(I64x2GeS_mach_simd_op)                   \
  V(I64x2ShrU_mach_simd_op)                  \
  V(I64x2ExtMulLowI32x4S_mach_simd_op)       \
  V(I64x2ExtMulHighI32x4S_mach_simd_op)      \
  V(I64x2ExtMulLowI32x4U_mach_simd_op)       \
  V(I64x2ExtMulHighI32x4U_mach_simd_op)      \
  V(I32x4Splat_mach_simd_op)                 \
  V(I32x4ExtractLane_mach_simd_op)           \
  V(I32x4ReplaceLane_mach_simd_op)           \
  V(I32x4SConvertF32x4_mach_simd_op)         \
  V(I32x4SConvertI16x8Low_mach_simd_op)      \
  V(I32x4SConvertI16x8High_mach_simd_op)     \
  V(I32x4Neg_mach_simd_op)                   \
  V(I32x4Shl_mach_simd_op)                   \
  V(I32x4ShrS_mach_simd_op)                  \
  V(I32x4Add_mach_simd_op)                   \
  V(I32x4Sub_mach_simd_op)                   \
  V(I32x4Mul_mach_simd_op)                   \
  V(I32x4MinS_mach_simd_op)                  \
  V(I32x4MaxS_mach_simd_op)                  \
  V(I32x4Eq_mach_simd_op)                    \
  V(I32x4Ne_mach_simd_op)                    \
  V(I32x4LtS_mach_simd_op)                   \
  V(I32x4LeS_mach_simd_op)                   \
  V(I32x4GtS_mach_simd_op)                   \
  V(I32x4GeS_mach_simd_op)                   \
  V(I32x4UConvertF32x4_mach_simd_op)         \
  V(I32x4UConvertI16x8Low_mach_simd_op)      \
  V(I32x4UConvertI16x8High_mach_simd_op)     \
  V(I32x4ShrU_mach_simd_op)                  \
  V(I32x4MinU_mach_simd_op)                  \
  V(I32x4MaxU_mach_simd_op)                  \
  V(I32x4LtU_mach_simd_op)                   \
  V(I32x4LeU_mach_simd_op)                   \
  V(I32x4GtU_mach_simd_op)                   \
  V(I32x4GeU_mach_simd_op)                   \
  V(I32x4Abs_mach_simd_op)                   \
  V(I32x4BitMask_mach_simd_op)               \
  V(I32x4DotI16x8S_mach_simd_op)             \
  V(I32x4ExtMulLowI16x8S_mach_simd_op)       \
  V(I32x4ExtMulHighI16x8S_mach_simd_op)      \
  V(I32x4ExtMulLowI16x8U_mach_simd_op)       \
  V(I32x4ExtMulHighI16x8U_mach_simd_op)      \
  V(I32x4ExtAddPairwiseI16x8S_mach_simd_op)  \
  V(I32x4ExtAddPairwiseI16x8U_mach_simd_op)  \
  V(I32x4TruncSatF64x2SZero_mach_simd_op)    \
  V(I32x4TruncSatF64x2UZero_mach_simd_op)    \
  V(I16x8Splat_mach_simd_op)                 \
  V(I16x8ExtractLaneU_mach_simd_op)          \
  V(I16x8ExtractLaneS_mach_simd_op)          \
  V(I16x8ReplaceLane_mach_simd_op)           \
  V(I16x8SConvertI8x16Low_mach_simd_op)      \
  V(I16x8SConvertI8x16High_mach_simd_op)     \
  V(I16x8Neg_mach_simd_op)                   \
  V(I16x8Shl_mach_simd_op)                   \
  V(I16x8ShrS_mach_simd_op)                  \
  V(I16x8SConvertI32x4_mach_simd_op)         \
  V(I16x8Add_mach_simd_op)                   \
  V(I16x8AddSatS_mach_simd_op)               \
  V(I16x8Sub_mach_simd_op)                   \
  V(I16x8SubSatS_mach_simd_op)               \
  V(I16x8Mul_mach_simd_op)                   \
  V(I16x8MinS_mach_simd_op)                  \
  V(I16x8MaxS_mach_simd_op)                  \
  V(I16x8Eq_mach_simd_op)                    \
  V(I16x8Ne_mach_simd_op)                    \
  V(I16x8LtS_mach_simd_op)                   \
  V(I16x8LeS_mach_simd_op)                   \
  V(I16x8GtS_mach_simd_op)                   \
  V(I16x8GeS_mach_simd_op)                   \
  V(I16x8UConvertI8x16Low_mach_simd_op)      \
  V(I16x8UConvertI8x16High_mach_simd_op)     \
  V(I16x8ShrU_mach_simd_op)                  \
  V(I16x8UConvertI32x4_mach_simd_op)         \
  V(I16x8AddSatU_mach_simd_op)               \
  V(I16x8SubSatU_mach_simd_op)               \
  V(I16x8MinU_mach_simd_op)                  \
  V(I16x8MaxU_mach_simd_op)                  \
  V(I16x8LtU_mach_simd_op)                   \
  V(I16x8LeU_mach_simd_op)                   \
  V(I16x8GtU_mach_simd_op)                   \
  V(I16x8GeU_mach_simd_op)                   \
  V(I16x8RoundingAverageU_mach_simd_op)      \
  V(I16x8Q15MulRSatS_mach_simd_op)           \
  V(I16x8Abs_mach_simd_op)                   \
  V(I16x8BitMask_mach_simd_op)               \
  V(I16x8ExtMulLowI8x16S_mach_simd_op)       \
  V(I16x8ExtMulHighI8x16S_mach_simd_op)      \
  V(I16x8ExtMulLowI8x16U_mach_simd_op)       \
  V(I16x8ExtMulHighI8x16U_mach_simd_op)      \
  V(I16x8ExtAddPairwiseI8x16S_mach_simd_op)  \
  V(I16x8ExtAddPairwiseI8x16U_mach_simd_op)  \
  V(I8x16Splat_mach_simd_op)                 \
  V(I8x16ExtractLaneU_mach_simd_op)          \
  V(I8x16ExtractLaneS_mach_simd_op)          \
  V(I8x16ReplaceLane_mach_simd_op)           \
  V(I8x16SConvertI16x8_mach_simd_op)         \
  V(I8x16Neg_mach_simd_op)                   \
  V(I8x16Shl_mach_simd_op)                   \
  V(I8x16ShrS_mach_simd_op)                  \
  V(I8x16Add_mach_simd_op)                   \
  V(I8x16AddSatS_mach_simd_op)               \
  V(I8x16Sub_mach_simd_op)                   \
  V(I8x16SubSatS_mach_simd_op)               \
  V(I8x16MinS_mach_simd_op)                  \
  V(I8x16MaxS_mach_simd_op)                  \
  V(I8x16Eq_mach_simd_op)                    \
  V(I8x16Ne_mach_simd_op)                    \
  V(I8x16LtS_mach_simd_op)                   \
  V(I8x16LeS_mach_simd_op)                   \
  V(I8x16GtS_mach_simd_op)                   \
  V(I8x16GeS_mach_simd_op)                   \
  V(I8x16UConvertI16x8_mach_simd_op)         \
  V(I8x16AddSatU_mach_simd_op)               \
  V(I8x16SubSatU_mach_simd_op)               \
  V(I8x16ShrU_mach_simd_op)                  \
  V(I8x16MinU_mach_simd_op)                  \
  V(I8x16MaxU_mach_simd_op)                  \
  V(I8x16LtU_mach_simd_op)                   \
  V(I8x16LeU_mach_simd_op)                   \
  V(I8x16GtU_mach_simd_op)                   \
  V(I8x16GeU_mach_simd_op)                   \
  V(I8x16RoundingAverageU_mach_simd_op)      \
  V(I8x16Popcnt_mach_simd_op)                \
  V(I8x16Abs_mach_simd_op)                   \
  V(I8x16BitMask_mach_simd_op)               \
  V(S128Zero_mach_simd_op)                   \
  V(S128Const_mach_simd_op)                  \
  V(S128Not_mach_simd_op)                    \
  V(S128And_mach_simd_op)                    \
  V(S128Or_mach_simd_op)                     \
  V(S128Xor_mach_simd_op)                    \
  V(S128Select_mach_simd_op)                 \
  V(S128AndNot_mach_simd_op)                 \
  V(I8x16Swizzle_mach_simd_op)               \
  V(I8x16Shuffle_mach_simd_op)               \
  V(V128AnyTrue_mach_simd_op)                \
  V(I64x2AllTrue_mach_simd_op)               \
  V(I32x4AllTrue_mach_simd_op)               \
  V(I16x8AllTrue_mach_simd_op)               \
  V(I8x16AllTrue_mach_simd_op)               \
  V(LoadTransform_mach_simd_op)              \
  V(LoadLane_mach_simd_op)                   \
  V(StoreLane_mach_simd_op)

#define VALUE_OP_LIST_N(V)  \
  COMMON_OP_LIST_N(V)       \
  SIMPLIFIED_OP_LIST_N(V)   \
  MACHINE_OP_LIST_N(V)      \
  MACHINE_SIMD_OP_LIST_N(V) \
  JS_OP_LIST_N(V)


#define ALL_OP_LIST_NAME(V) \
  CONTROL_OP_LIST_N(V)   \
  VALUE_OP_LIST_N(V)
namespace v8 {
namespace internal {
namespace compiler {

// Declare an enumeration with all the opcodes at all levels so that they
// can be globally, uniquely numbered.
class V8_EXPORT_PRIVATE IrOpcode {
 public:
  enum Value {
#define DECLARE_OPCODE(x, ...) k##x,
    ALL_OP_LIST(DECLARE_OPCODE)
#undef DECLARE_OPCODE
        kLast = -1
#define COUNT_OPCODE(...) +1
                ALL_OP_LIST(COUNT_OPCODE)
#undef COUNT_OPCODE
  };

  // Returns the mnemonic name of an opcode.
  static char const* Mnemonic(Value value);
  static char const* Mnemonic(int value);

  // Returns true if opcode for common operator.
  static bool IsCommonOpcode(Value value) {
    return kStart <= value && value <= kStaticAssert;
  }

  // Returns true if opcode for control operator.
  static bool IsControlOpcode(Value value) {
    return kStart <= value && value <= kEnd;
  }

  // Returns true if opcode for JavaScript operator.
  static bool IsJsOpcode(Value value) {
    return kJSEqual <= value && value <= kJSDebugger;
  }

  // Returns true if opcode for constant operator.
  static bool IsConstantOpcode(Value value) {
#define CASE(Name) \
  case k##Name:    \
    return true;
    switch (value) {
      CONSTANT_OP_LIST(CASE);
      default:
        return false;
    }
#undef CASE
    UNREACHABLE();
  }

  static bool IsPhiOpcode(Value value) {
    return value == kPhi || value == kEffectPhi;
  }

  static bool IsMergeOpcode(Value value) {
    return value == kMerge || value == kLoop;
  }

  static bool IsIfProjectionOpcode(Value value) {
    return kIfTrue <= value && value <= kIfDefault;
  }

  // Returns true if opcode terminates control flow in a graph (i.e.
  // respective nodes are expected to have control uses by the graphs {End}
  // node only).
  static bool IsGraphTerminator(Value value) {
    return value == kDeoptimize || value == kReturn || value == kTailCall ||
           value == kTerminate || value == kThrow;
  }

  // Returns true if opcode can be inlined.
  static bool IsInlineeOpcode(Value value) {
    return value == kJSConstruct || value == kJSCall;
  }

  // Returns true if opcode for comparison operator.
  static bool IsComparisonOpcode(Value value) {
#define CASE(Name, ...) \
  case k##Name:         \
    return true;
    switch (value) {
      JS_COMPARE_BINOP_LIST(CASE);
      SIMPLIFIED_COMPARE_BINOP_LIST(CASE);
      MACHINE_COMPARE_BINOP_LIST(CASE);
      default:
        return false;
    }
#undef CASE
    UNREACHABLE();
  }

  static bool IsContextChainExtendingOpcode(Value value) {
    return kJSCreateFunctionContext <= value && value <= kJSCreateBlockContext;
  }

  // These opcode take the feedback vector as an input, and implement
  // feedback-collecting logic in generic lowering.
  static bool IsFeedbackCollectingOpcode(Value value) {
#define CASE(Name, ...) \
  case k##Name:         \
    return true;
    switch (value) {
      JS_ARITH_BINOP_LIST(CASE)
      JS_ARITH_UNOP_LIST(CASE)
      JS_BITWISE_BINOP_LIST(CASE)
      JS_BITWISE_UNOP_LIST(CASE)
      JS_COMPARE_BINOP_LIST(CASE)
      case kJSCall:
      case kJSCallWithArrayLike:
      case kJSCallWithSpread:
      case kJSCloneObject:
      case kJSConstruct:
      case kJSConstructWithArrayLike:
      case kJSConstructWithSpread:
      case kJSCreateEmptyLiteralArray:
      case kJSCreateLiteralArray:
      case kJSCreateLiteralObject:
      case kJSCreateLiteralRegExp:
      case kJSForInNext:
      case kJSForInPrepare:
      case kJSGetIterator:
      case kJSGetTemplateObject:
      case kJSHasProperty:
      case kJSInstanceOf:
      case kJSLoadGlobal:
      case kJSLoadNamed:
      case kJSLoadNamedFromSuper:
      case kJSLoadProperty:
      case kJSStoreDataPropertyInLiteral:
      case kJSStoreGlobal:
      case kJSStoreInArrayLiteral:
      case kJSStoreNamed:
      case kJSStoreNamedOwn:
      case kJSStoreProperty:
        return true;
      default:
        return false;
    }
#undef CASE
    UNREACHABLE();
  }

  static bool IsFeedbackCollectingOpcode(int16_t value) {
    DCHECK(0 <= value && value <= kLast);
    return IsFeedbackCollectingOpcode(static_cast<IrOpcode::Value>(value));
  }
};

V8_EXPORT_PRIVATE std::ostream& operator<<(std::ostream&, IrOpcode::Value);

}  // namespace compiler
}  // namespace internal
}  // namespace v8

#endif  // V8_COMPILER_OPCODES_H_
