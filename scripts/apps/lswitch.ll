; ModuleID = 'a.ll'

%Opaque = type opaque
%Context = type opaque

@fp_dataplane_Ropq = global %Opaque* null
@learn_Ropq = global %Opaque* null
@forward_Ropq = global %Opaque* null

declare void @fp_raise_event(%Context*, void (%Context*)*)

declare void @fp_set_field(%Context*, i32, i32, i8*)

declare void @fp_output_port(%Context*, i32)

declare void @fp_drop(%Context*)

declare i1 @fp_port_id_is_down(%Opaque*, i32)

declare i1 @fp_port_id_is_up(%Opaque*, i32)

declare void @fp_clear(%Context*)

declare i32 @fp_get_flood_port(%Opaque*)

declare i32 @fp_get_controller_port(%Opaque*)

declare i32 @fp_get_all_port(%Opaque*)

declare void @fp_goto_table(%Context*, %Opaque*, ...)

declare void @fp_del_miss(%Opaque*)

declare void @fp_write_set_field(%Context*, i32, i32, i8*)

declare void @fp_del_flow(%Opaque*, i8*)

declare i32 @fp_get_packet_in_phys_port(%Context*)

declare i32 @fp_get_packet_in_port(%Context*)

declare void @fp_add_new_flow(%Opaque*, void (%Opaque*, %Opaque*, %Context*)*, i8*, i32, i32)

declare void @fp_add_init_flow(%Opaque*, void (%Opaque*, %Opaque*, %Context*)*, i8*, i32, i32)

declare i32 @fp_get_reflow_port(%Opaque*)

declare i32 @fp_get_port_by_id(%Opaque*, i32)

declare %Opaque* @fp_create_table(%Opaque*, i32, i32, i32, i32)

declare void @fp_write_output(%Context*, i32)

declare void @fp_add_miss(%Opaque*, void (%Opaque*, %Opaque*, %Context*)*, i32, i32)

declare void @fp_advance_header(%Context*, i32)

declare i8* @fp_read_field(%Context*, i32, i8*)

declare void @fp_alias_bind(%Context*, i32, i32, i32, i32)

declare i32 @fp_get_flow_egress(%Opaque*)

declare void @fp_bind_field(%Context*, i32, i32, i32)

declare void @fp_bind_header(%Context*, i32)

declare i32 @puts(i8*)

define i48 @__KEYFORM_learn_Fii(i48 %_Fethernet_src) {
entry:
  %reserved.0 = alloca i48
  %retv = alloca i48
  %0 = alloca i48
  %1 = alloca i48
  store i48 %_Fethernet_src, i48* %1
  store i48 0, i48* %retv
  store i48 0, i48* %reserved.0
  %2 = load i48* %reserved.0
  %3 = load i48* %1
  %4 = or i48 %2, %3
  store i48 %4, i48* %reserved.0
  %5 = load i48* %retv
  %6 = load i48* %reserved.0
  %7 = shl i48 %6, 0
  %8 = or i48 %5, %7
  store i48 %8, i48* %retv
  %9 = load i48* %retv
  store i48 %9, i48* %0
  br label %exit

exit:                                             ; preds = %entry
  %10 = load i48* %0
  ret i48 %10
}

define i48 @__KEYFORM_forward_Fii(i48 %_Fethernet_src) {
entry:
  %reserved.1 = alloca i48
  %retv = alloca i48
  %0 = alloca i48
  %1 = alloca i48
  store i48 %_Fethernet_src, i48* %1
  store i48 0, i48* %retv
  store i48 0, i48* %reserved.1
  %2 = load i48* %reserved.1
  %3 = load i48* %1
  %4 = or i48 %2, %3
  store i48 %4, i48* %reserved.1
  %5 = load i48* %retv
  %6 = load i48* %reserved.1
  %7 = shl i48 %6, 0
  %8 = or i48 %5, %7
  store i48 %8, i48* %retv
  %9 = load i48* %retv
  store i48 %9, i48* %0
  br label %exit

exit:                                             ; preds = %entry
  %10 = load i48* %0
  ret i48 %10
}

define void @eth_d(%Context* %__cxt) {
entry:
  %_Fethernet_src = alloca i48
  %_Fethernet_dst = alloca i48
  %0 = alloca %Context*
  store %Context* %__cxt, %Context** %0
  %1 = load %Context** %0
  call void @fp_bind_header(%Context* %1, i32 0)
  %2 = load %Context** %0
  call void @fp_bind_field(%Context* %2, i32 0, i32 0, i32 6)
  store i48 0, i48* %_Fethernet_dst
  %3 = load %Context** %0
  call void @fp_bind_field(%Context* %3, i32 1, i32 6, i32 6)
  store i48 0, i48* %_Fethernet_src
  %4 = load %Context** %0
  call void @fp_advance_header(%Context* %4, i32 14)
  %5 = load %Context** %0
  %6 = load %Opaque** @learn_Ropq
  call void (%Context*, %Opaque*, ...)* @fp_goto_table(%Context* %5, %Opaque* %6, i32 1, i32 1)
  br label %exit

exit:                                             ; preds = %entry
  ret void
}

define void @_ADDED_FLOW_learn_f1(%Opaque* %__flow_self, %Opaque* %__table, %Context* %__cxt) {
entry:
  %_Fethernet_src = alloca i48
  %0 = alloca %Opaque*
  store %Opaque* %__flow_self, %Opaque** %0
  %1 = alloca %Opaque*
  store %Opaque* %__table, %Opaque** %1
  %2 = alloca %Context*
  store %Context* %__cxt, %Context** %2
  store i48 0, i48* %_Fethernet_src
  %3 = load %Context** %2
  %4 = load %Opaque** @forward_Ropq
  call void (%Context*, %Opaque*, ...)* @fp_goto_table(%Context* %3, %Opaque* %4, i32 1, i32 0)
  br label %exit

exit:                                             ; preds = %entry
  ret void
}

define void @_ADDED_FLOW_forward_f1(%Opaque* %__flow_self, %Opaque* %__table, %Context* %__cxt) {
entry:
  %_Fethernet_dst = alloca i48
  %0 = alloca %Opaque*
  store %Opaque* %__flow_self, %Opaque** %0
  %1 = alloca %Opaque*
  store %Opaque* %__table, %Opaque** %1
  %2 = alloca %Context*
  store %Context* %__cxt, %Context** %2
  store i48 0, i48* %_Fethernet_dst
  %3 = load %Context** %2
  %4 = load %Opaque** %0
  %5 = call i32 @fp_get_flow_egress(%Opaque* %4)
  call void @fp_output_port(%Context* %3, i32 %5)
  br label %exit

exit:                                             ; preds = %entry
  ret void
}

define void @learn_mac(%Context* %__cxt) {
entry:
  %reserved.3 = alloca i48
  %reserved.2 = alloca i48
  %_Fethernet_src = alloca i48
  %0 = alloca %Context*
  store %Context* %__cxt, %Context** %0
  %1 = load %Context** %0
  %2 = bitcast i48* %_Fethernet_src to i8*
  %3 = call i8* @fp_read_field(%Context* %1, i32 1, i8* %2)
  %4 = bitcast i8* %3 to i48*
  %5 = load i48* %4
  store i48 %5, i48* %_Fethernet_src
  %6 = load i48* %_Fethernet_src
  %7 = call i48 @__KEYFORM_learn_Fii(i48 %6)
  store i48 %7, i48* %reserved.2
  %8 = load %Opaque** @learn_Ropq
  %9 = bitcast i48* %reserved.2 to i8*
  call void @fp_add_new_flow(%Opaque* %8, void (%Opaque*, %Opaque*, %Context*)* @_ADDED_FLOW_learn_f1, i8* %9, i32 60, i32 0)
  %10 = load i48* %_Fethernet_src
  %11 = call i48 @__KEYFORM_forward_Fii(i48 %10)
  store i48 %11, i48* %reserved.3
  %12 = load %Opaque** @forward_Ropq
  %13 = bitcast i48* %reserved.3 to i8*
  %14 = load %Context** %0
  %15 = call i32 @fp_get_packet_in_port(%Context* %14)
  call void @fp_add_new_flow(%Opaque* %12, void (%Opaque*, %Opaque*, %Context*)* @_ADDED_FLOW_forward_f1, i8* %13, i32 60, i32 %15)
  br label %exit

exit:                                             ; preds = %entry
  ret void
}

define void @_FLOW_learn_f_miss(%Opaque* %__flow_self, %Opaque* %__table, %Context* %__cxt) {
entry:
  %_Fethernet_src = alloca i48
  %0 = alloca %Opaque*
  store %Opaque* %__flow_self, %Opaque** %0
  %1 = alloca %Opaque*
  store %Opaque* %__table, %Opaque** %1
  %2 = alloca %Context*
  store %Context* %__cxt, %Context** %2
  store i48 0, i48* %_Fethernet_src
  %3 = load %Context** %2
  call void @fp_raise_event(%Context* %3, void (%Context*)* @learn_mac)
  %4 = load %Context** %2
  %5 = load %Opaque** @forward_Ropq
  call void (%Context*, %Opaque*, ...)* @fp_goto_table(%Context* %4, %Opaque* %5, i32 1, i32 0)
  br label %exit

exit:                                             ; preds = %entry
  ret void
}

define void @_FLOW_forward_f_miss(%Opaque* %__flow_self, %Opaque* %__table, %Context* %__cxt) {
entry:
  %_Fethernet_dst = alloca i48
  %0 = alloca %Opaque*
  store %Opaque* %__flow_self, %Opaque** %0
  %1 = alloca %Opaque*
  store %Opaque* %__table, %Opaque** %1
  %2 = alloca %Context*
  store %Context* %__cxt, %Context** %2
  store i48 0, i48* %_Fethernet_dst
  %3 = load %Context** %2
  %4 = load %Opaque** @fp_dataplane_Ropq
  %5 = call i32 @fp_get_flood_port(%Opaque* %4)
  call void @fp_output_port(%Context* %3, i32 %5)
  br label %exit

exit:                                             ; preds = %entry
  ret void
}

define void @load(%Opaque* %dp) {
entry:
  %0 = alloca %Opaque*
  store %Opaque* %dp, %Opaque** %0
  %1 = load %Opaque** %0
  store %Opaque* %1, %Opaque** @fp_dataplane_Ropq
  %2 = load %Opaque** @fp_dataplane_Ropq
  %3 = call %Opaque* @fp_create_table(%Opaque* %2, i32 1, i32 6, i32 1000, i32 0)
  store %Opaque* %3, %Opaque** @learn_Ropq
  %4 = load %Opaque** @learn_Ropq
  call void @fp_add_miss(%Opaque* %4, void (%Opaque*, %Opaque*, %Context*)* @_FLOW_learn_f_miss, i32 0, i32 0)
  %5 = load %Opaque** @fp_dataplane_Ropq
  %6 = call %Opaque* @fp_create_table(%Opaque* %5, i32 2, i32 6, i32 1000, i32 0)
  store %Opaque* %6, %Opaque** @forward_Ropq
  %7 = load %Opaque** @forward_Ropq
  call void @fp_add_miss(%Opaque* %7, void (%Opaque*, %Opaque*, %Context*)* @_FLOW_forward_f_miss, i32 0, i32 0)
  br label %exit

exit:                                             ; preds = %entry
  ret void
}

define void @process(%Context* %__cxt) {
entry:
  %0 = alloca %Context*
  store %Context* %__cxt, %Context** %0
  %1 = load %Context** %0
  call void @eth_d(%Context* %1)
  br label %exit

exit:                                             ; preds = %entry
  ret void
}

define i32 @port_changed(i32 %id) {
entry:
  %0 = alloca i32
  %1 = alloca i32
  store i32 %id, i32* %1
  store i32 0, i32* %0
  br label %exit

exit:                                             ; preds = %entry
  %2 = load i32* %0
  ret i32 %2
}

define i32 @ports() {
entry:
  %0 = alloca i32
  store i32 0, i32* %0
  br label %exit

exit:                                             ; preds = %entry
  %1 = load i32* %0
  ret i32 %1
}
