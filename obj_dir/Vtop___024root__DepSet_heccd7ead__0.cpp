// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__0\n"); );
    // Body
    if (vlSelf->rst_ni) {
        vlSelf->top__DOT__sum_module__DOT__sum_reg 
            = ((0U == (IData)(vlSelf->top__DOT__sum_module__DOT__count_reg))
                ? 0U : (0xffffU & (IData)(vlSelf->top__DOT__sum_module__DOT__add_wire)));
        vlSelf->top__DOT__sum_module__DOT__count_reg 
            = (0xffU & ((IData)(vlSelf->top__DOT__sum_module__DOT__done_wire)
                         ? (IData)(vlSelf->n_i) : ((IData)(vlSelf->top__DOT__sum_module__DOT__count_wire) 
                                                   - (IData)(1U))));
    } else {
        vlSelf->top__DOT__sum_module__DOT__sum_reg = 0U;
        vlSelf->top__DOT__sum_module__DOT__count_reg = 0U;
    }
    vlSelf->sum_o = vlSelf->top__DOT__sum_module__DOT__sum_reg;
    vlSelf->top__DOT__sum_module__DOT__count_wire = vlSelf->top__DOT__sum_module__DOT__count_reg;
    vlSelf->top__DOT__sum_module__DOT__done_wire = 
        (0U == (IData)(vlSelf->top__DOT__sum_module__DOT__count_reg));
    vlSelf->done_o = (0U == (IData)(vlSelf->top__DOT__sum_module__DOT__count_reg));
}

VL_INLINE_OPT void Vtop___024root___combo__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->top__DOT__sum_module__DOT__add_wire = (0xffffU 
                                                   & ((IData)(vlSelf->top__DOT__sum_module__DOT__sum_reg) 
                                                      + 
                                                      ((IData)(vlSelf->rst_ni)
                                                        ? 
                                                       ((0U 
                                                         == (IData)(vlSelf->top__DOT__sum_module__DOT__count_reg))
                                                         ? 0U
                                                         : 
                                                        ((0xff00U 
                                                          & ((- (IData)(
                                                                        (1U 
                                                                         & ((IData)(vlSelf->data_i) 
                                                                            >> 7U)))) 
                                                             << 8U)) 
                                                         | (IData)(vlSelf->data_i)))
                                                        : 0U)));
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk_i) & (~ (IData)(vlSelf->__Vclklast__TOP__clk_i)))) {
        Vtop___024root___sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    Vtop___024root___combo__TOP__0(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk_i = vlSelf->clk_i;
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((vlSelf->rst_ni & 0xfeU))) {
        Verilated::overWidthError("rst_ni");}
}
#endif  // VL_DEBUG
