void Builtins::Generate_CallFunction(MacroAssembler* masm,
                                     ConvertReceiverMode mode) {
  // ----------- S t a t e -------------
  //  -- a0 : the number of arguments (not including the receiver)
  //  -- a1 : the function to call (checked to be a JSFunction)
  // -----------------------------------
__ RecordComment("[  AssertFunction(a1);");
  __ AssertFunction(a1);
__ RecordComment("]");

  // See ES6 section 9.2.1 [[Call]] ( thisArgument, argumentsList)
  // Check that function is not a "classConstructor".
  Label class_constructor;
  __ LoadTaggedPointerField(
      a2, FieldMemOperand(a1, JSFunction::kSharedFunctionInfoOffset));
__ RecordComment("[  Lwu(a3, FieldMemOperand(a2, SharedFunctionInfo::kFlagsOffset));");
  __ Lwu(a3, FieldMemOperand(a2, SharedFunctionInfo::kFlagsOffset));
__ RecordComment("]");
  __ And(kScratchReg, a3,
         Operand(SharedFunctionInfo::IsClassConstructorBit::kMask));
__ RecordComment("[  Branch(&class_constructor, ne, kScratchReg, Operand(zero_reg));");
  __ Branch(&class_constructor, ne, kScratchReg, Operand(zero_reg));
__ RecordComment("]");

  // Enter the context of the function; ToObject has to run in the function
  // context, and we also need to take the global proxy from the function
  // context in case of conversion.
  __ LoadTaggedPointerField(cp,
                            FieldMemOperand(a1, JSFunction::kContextOffset));
  // We need to convert the receiver for non-native sloppy mode functions.
  Label done_convert;
__ RecordComment("[  Lwu(a3, FieldMemOperand(a2, SharedFunctionInfo::kFlagsOffset));");
  __ Lwu(a3, FieldMemOperand(a2, SharedFunctionInfo::kFlagsOffset));
__ RecordComment("]");
  __ And(kScratchReg, a3,
         Operand(SharedFunctionInfo::IsNativeBit::kMask |
                 SharedFunctionInfo::IsStrictBit::kMask));
__ RecordComment("[  Branch(&done_convert, ne, kScratchReg, Operand(zero_reg));");
  __ Branch(&done_convert, ne, kScratchReg, Operand(zero_reg));
__ RecordComment("]");
  {
    // ----------- S t a t e -------------
    //  -- a0 : the number of arguments (not including the receiver)
    //  -- a1 : the function to call (checked to be a JSFunction)
    //  -- a2 : the shared function info.
    //  -- cp : the function context.
    // -----------------------------------

    if (mode == ConvertReceiverMode::kNullOrUndefined) {
      // Patch receiver to global proxy.
__ RecordComment("[  LoadGlobalProxy(a3);");
      __ LoadGlobalProxy(a3);
__ RecordComment("]");
    } else {
      Label convert_to_object, convert_receiver;
__ RecordComment("[  LoadReceiver(a3, a0);");
      __ LoadReceiver(a3, a0);
__ RecordComment("]");
__ RecordComment("[  JumpIfSmi(a3, &convert_to_object);");
      __ JumpIfSmi(a3, &convert_to_object);
__ RecordComment("]");
      STATIC_ASSERT(LAST_JS_RECEIVER_TYPE == LAST_TYPE);
__ RecordComment("[  GetObjectType(a3, a4, a4);");
      __ GetObjectType(a3, a4, a4);
__ RecordComment("]");
      __ Branch(&done_convert, Ugreater_equal, a4,
                Operand(FIRST_JS_RECEIVER_TYPE));
      if (mode != ConvertReceiverMode::kNotNullOrUndefined) {
        Label convert_global_proxy;
__ RecordComment("[  JumpIfRoot(a3, RootIndex::kUndefinedValue, &convert_global_proxy);");
        __ JumpIfRoot(a3, RootIndex::kUndefinedValue, &convert_global_proxy);
__ RecordComment("]");
__ RecordComment("[  JumpIfNotRoot(a3, RootIndex::kNullValue, &convert_to_object);");
        __ JumpIfNotRoot(a3, RootIndex::kNullValue, &convert_to_object);
__ RecordComment("]");
__ RecordComment("[  bind(&convert_global_proxy);");
        __ bind(&convert_global_proxy);
__ RecordComment("]");
        {
          // Patch receiver to global proxy.
__ RecordComment("[  LoadGlobalProxy(a3);");
          __ LoadGlobalProxy(a3);
__ RecordComment("]");
        }
__ RecordComment("[  Branch(&convert_receiver);");
        __ Branch(&convert_receiver);
__ RecordComment("]");
      }
__ RecordComment("[  bind(&convert_to_object);");
      __ bind(&convert_to_object);
__ RecordComment("]");
      {
        // Convert receiver using ToObject.
        // TODO(bmeurer): Inline the allocation here to avoid building the frame
        // in the fast case? (fall back to AllocateInNewSpace?)
        FrameScope scope(masm, StackFrame::INTERNAL);
__ RecordComment("[  SmiTag(a0);");
        __ SmiTag(a0);
__ RecordComment("]");
__ RecordComment("[  Push(a0, a1);");
        __ Push(a0, a1);
__ RecordComment("]");
__ RecordComment("[  Move(a0, a3);");
        __ Move(a0, a3);
__ RecordComment("]");
__ RecordComment("[  Push(cp);");
        __ Push(cp);
__ RecordComment("]");
        __ Call(BUILTIN_CODE(masm->isolate(), ToObject),
                RelocInfo::CODE_TARGET);
__ RecordComment("[  Pop(cp);");
        __ Pop(cp);
__ RecordComment("]");
__ RecordComment("[  Move(a3, a0);");
        __ Move(a3, a0);
__ RecordComment("]");
__ RecordComment("[  Pop(a0, a1);");
        __ Pop(a0, a1);
__ RecordComment("]");
__ RecordComment("[  SmiUntag(a0);");
        __ SmiUntag(a0);
__ RecordComment("]");
      }
      __ LoadTaggedPointerField(
          a2, FieldMemOperand(a1, JSFunction::kSharedFunctionInfoOffset));
__ RecordComment("[  bind(&convert_receiver);");
      __ bind(&convert_receiver);
__ RecordComment("]");
    }
__ RecordComment("[  StoreReceiver(a3, a0, kScratchReg);");
    __ StoreReceiver(a3, a0, kScratchReg);
__ RecordComment("]");
  }
__ RecordComment("[  bind(&done_convert);");
  __ bind(&done_convert);
__ RecordComment("]");

  // ----------- S t a t e -------------
  //  -- a0 : the number of arguments (not including the receiver)
  //  -- a1 : the function to call (checked to be a JSFunction)
  //  -- a2 : the shared function info.
  //  -- cp : the function context.
  // -----------------------------------

  __ Lhu(a2,
         FieldMemOperand(a2, SharedFunctionInfo::kFormalParameterCountOffset));
__ RecordComment("[  InvokeFunctionCode(a1, no_reg, a2, a0, InvokeType::kJump);");
  __ InvokeFunctionCode(a1, no_reg, a2, a0, InvokeType::kJump);
__ RecordComment("]");

  // The function is a "classConstructor", need to raise an exception.
__ RecordComment("[  bind(&class_constructor);");
  __ bind(&class_constructor);
__ RecordComment("]");
  {
    FrameScope frame(masm, StackFrame::INTERNAL);
__ RecordComment("[  Push(a1);");
    __ Push(a1);
__ RecordComment("]");
__ RecordComment("[  CallRuntime(Runtime::kThrowConstructorNonCallableError);");
    __ CallRuntime(Runtime::kThrowConstructorNonCallableError);
__ RecordComment("]");
  }
}
