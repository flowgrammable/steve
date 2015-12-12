;../../beaker/test/steve/decode-1.stv
; ModuleID = 'a.ll'

%__Port__ = type opaque
%__Table__ = type opaque
%__Key__ = type opaque
%Context = type opaque

@p1_Rprt = global %__Port__* null
@p2_Rprt = global %__Port__* null
@t1_R = global %__Table__* null
@t2_R = global %__Table__* null
@0 = private unnamed_addr constant [3 x i8] c"p1\00"
@1 = private unnamed_addr constant [3 x i8] c"p2\00"

declare %__Port__* @fp_get_port(i8*)

declare %__Key__* @fp_gather(%Context*, i32, ...)

declare void @fp_add_flow(%__Table__*, void (%__Table__*, %Context*)*)

declare i32 @fp_load_field(%Context*, i32)

declare void @fp_goto_table(%Context*, %__Key__*, %__Table__*)

declare %__Table__* @fp_get_table(i32, i32, i32, i32)

declare void @fp_advance(%Context*, i32)

declare void @fp_alias_bind(%Context*, i32, i32, i32, i32)

declare void @fp_bind_field(%Context*, i32, i32, i32)

declare void @fp_bind_header(%Context*, i32, i32)

define void @eth_d(%Context* %__cxt__) {
entry:
  %_Exeth_type = alloca i32
  %_Exeth_dst = alloca i32
  %_Exeth_src = alloca i32
  %0 = alloca %Context*
  store %Context* %__cxt__, %Context** %0
  %1 = load %Context** %0
  call void @fp_bind_field(%Context* %1, i32 2, i32 0, i32 4)
  %2 = load %Context** %0
  %3 = call i32 @fp_load_field(%Context* %2, i32 2)
  store i32 %3, i32* %_Exeth_src
  %4 = load %Context** %0
  call void @fp_bind_field(%Context* %4, i32 3, i32 4, i32 4)
  %5 = load %Context** %0
  %6 = call i32 @fp_load_field(%Context* %5, i32 3)
  store i32 %6, i32* %_Exeth_dst
  %7 = load %Context** %0
  call void @fp_bind_field(%Context* %7, i32 4, i32 8, i32 4)
  %8 = load %Context** %0
  %9 = call i32 @fp_load_field(%Context* %8, i32 4)
  store i32 %9, i32* %_Exeth_type
  %10 = load i32* %_Exeth_type
  switch i32 %10, label %switch.done [
    i32 0, label %switch.c
    i32 1, label %switch.c1
  ]

switch.done:                                      ; preds = %switch.c1, %switch.c, %entry
  br label %exit

switch.c:                                         ; preds = %entry
  %11 = load %Context** %0
  call void @fp_advance(%Context* %11, i32 12)
  %12 = load %Context** %0
  call void @ipv4_d(%Context* %12)
  br label %switch.done

switch.c1:                                        ; preds = %entry
  %13 = load %Context** %0
  call void @fp_advance(%Context* %13, i32 12)
  %14 = load %Context** %0
  call void @ipv4_d(%Context* %14)
  br label %switch.done

exit:                                             ; preds = %switch.done
  ret void
}

define void @ipv4_d(%Context* %__cxt__) {
entry:
  %key = alloca %__Key__*
  %_Exipv4_protocol = alloca i32
  %_Exipv4_dst = alloca i32
  %0 = alloca %Context*
  store %Context* %__cxt__, %Context** %0
  %1 = load %Context** %0
  call void @fp_bind_field(%Context* %1, i32 0, i32 4, i32 4)
  %2 = load %Context** %0
  %3 = call i32 @fp_load_field(%Context* %2, i32 0)
  store i32 %3, i32* %_Exipv4_dst
  %4 = load %Context** %0
  call void @fp_bind_field(%Context* %4, i32 1, i32 8, i32 4)
  %5 = load %Context** %0
  %6 = call i32 @fp_load_field(%Context* %5, i32 1)
  store i32 %6, i32* %_Exipv4_protocol
  %7 = load i32* %_Exipv4_protocol
  switch i32 %7, label %switch.done [
    i32 0, label %switch.c
  ]

switch.done:                                      ; preds = %switch.c, %entry
  br label %exit

switch.c:                                         ; preds = %entry
  %8 = load %Context** %0
  call void @fp_advance(%Context* %8, i32 12)
  %9 = load %Context** %0
  %10 = call %__Key__* (%Context*, i32, ...)* @fp_gather(%Context* %9, i32 1, i32 0)
  store %__Key__* %10, %__Key__** %key
  %11 = load %Context** %0
  %12 = load %__Key__** %key
  %13 = load %__Table__** @t2_R
  call void @fp_goto_table(%Context* %11, %__Key__* %12, %__Table__* %13)
  br label %switch.done

exit:                                             ; preds = %switch.done
  ret void
}

define void @t1_Flw0(%__Table__* %__table__, %Context* %__cxt__) {
entry:
  %0 = alloca %__Table__*
  store %__Table__* %__table__, %__Table__** %0
  %1 = alloca %Context*
  store %Context* %__cxt__, %Context** %1
  br label %exit

exit:                                             ; preds = %entry
  ret void
}

define void @t1_Flw1(%__Table__* %__table__, %Context* %__cxt__) {
entry:
  %0 = alloca %__Table__*
  store %__Table__* %__table__, %__Table__** %0
  %1 = alloca %Context*
  store %Context* %__cxt__, %Context** %1
  br label %exit

exit:                                             ; preds = %entry
  ret void
}

define void @t2_Flw2(%__Table__* %__table__, %Context* %__cxt__) {
entry:
  %0 = alloca %__Table__*
  store %__Table__* %__table__, %__Table__** %0
  %1 = alloca %Context*
  store %Context* %__cxt__, %Context** %1
  %2 = load %Context** %1
  call void @ipv4_d(%Context* %2)
  br label %exit

exit:                                             ; preds = %entry
  ret void
}

define void @t2_Flw3(%__Table__* %__table__, %Context* %__cxt__) {
entry:
  %0 = alloca %__Table__*
  store %__Table__* %__table__, %__Table__** %0
  %1 = alloca %Context*
  store %Context* %__cxt__, %Context** %1
  %2 = load %Context** %1
  call void @eth_d(%Context* %2)
  br label %exit

exit:                                             ; preds = %entry
  ret void
}

define void @load() {
entry:
  %0 = call %__Port__* @fp_get_port(i8* getelementptr inbounds ([3 x i8]* @0, i32 0, i32 0))
  store %__Port__* %0, %__Port__** @p1_Rprt
  %1 = call %__Port__* @fp_get_port(i8* getelementptr inbounds ([3 x i8]* @1, i32 0, i32 0))
  store %__Port__* %1, %__Port__** @p2_Rprt
  %2 = call %__Table__* @fp_get_table(i32 1, i32 8, i32 1000, i32 0)
  store %__Table__* %2, %__Table__** @t1_R
  %3 = load %__Table__** @t1_R
  call void @fp_add_flow(%__Table__* %3, void (%__Table__*, %Context*)* @t1_Flw0)
  %4 = load %__Table__** @t1_R
  call void @fp_add_flow(%__Table__* %4, void (%__Table__*, %Context*)* @t1_Flw1)
  %5 = call %__Table__* @fp_get_table(i32 2, i32 4, i32 1000, i32 0)
  store %__Table__* %5, %__Table__** @t2_R
  %6 = load %__Table__** @t2_R
  call void @fp_add_flow(%__Table__* %6, void (%__Table__*, %Context*)* @t2_Flw2)
  %7 = load %__Table__** @t2_R
  call void @fp_add_flow(%__Table__* %7, void (%__Table__*, %Context*)* @t2_Flw3)
  br label %exit

exit:                                             ; preds = %entry
  ret void
}

define void @process(%Context* %__cxt__) {
entry:
  %0 = alloca %Context*
  store %Context* %__cxt__, %Context** %0
  %1 = load %Context** %0
  call void @eth_d(%Context* %1)
  br label %exit

exit:                                             ; preds = %entry
  ret void
}

define i32 @port_num() {
entry:
  %0 = alloca i32
  store i32 2, i32* %0
  br label %exit

exit:                                             ; preds = %entry
  %1 = load i32* %0
  ret i32 %1
}
