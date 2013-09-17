/* state-pe-d-flipflop.c generated by valac 0.20.1, the Vala compiler
 * generated from state-pe-d-flipflop.vala, do not modify */

/* 
 * SmartSim - Digital Logic Circuit Designer and Simulator
 *   
 *   Expansion Version
 *   
 *   Filename: componentstate/pe-d-flipflop.vala
 *   
 *   Copyright Ashley Newson 2012
 */

#include <glib.h>
#include <glib-object.h>
#include <cairo.h>


#define TYPE_COMPONENT_STATE (component_state_get_type ())
#define COMPONENT_STATE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_COMPONENT_STATE, ComponentState))
#define COMPONENT_STATE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_COMPONENT_STATE, ComponentStateClass))
#define IS_COMPONENT_STATE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_COMPONENT_STATE))
#define IS_COMPONENT_STATE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_COMPONENT_STATE))
#define COMPONENT_STATE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_COMPONENT_STATE, ComponentStateClass))

typedef struct _ComponentState ComponentState;
typedef struct _ComponentStateClass ComponentStateClass;
typedef struct _ComponentStatePrivate ComponentStatePrivate;

#define TYPE_COMPILED_CIRCUIT (compiled_circuit_get_type ())
#define COMPILED_CIRCUIT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_COMPILED_CIRCUIT, CompiledCircuit))
#define COMPILED_CIRCUIT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_COMPILED_CIRCUIT, CompiledCircuitClass))
#define IS_COMPILED_CIRCUIT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_COMPILED_CIRCUIT))
#define IS_COMPILED_CIRCUIT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_COMPILED_CIRCUIT))
#define COMPILED_CIRCUIT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_COMPILED_CIRCUIT, CompiledCircuitClass))

typedef struct _CompiledCircuit CompiledCircuit;
typedef struct _CompiledCircuitClass CompiledCircuitClass;

#define TYPE_COMPONENT_INST (component_inst_get_type ())
#define COMPONENT_INST(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_COMPONENT_INST, ComponentInst))
#define COMPONENT_INST_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_COMPONENT_INST, ComponentInstClass))
#define IS_COMPONENT_INST(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_COMPONENT_INST))
#define IS_COMPONENT_INST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_COMPONENT_INST))
#define COMPONENT_INST_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_COMPONENT_INST, ComponentInstClass))

typedef struct _ComponentInst ComponentInst;
typedef struct _ComponentInstClass ComponentInstClass;

#define TYPE_PE_DFLIPFLOP_COMPONENT_STATE (pe_dflipflop_component_state_get_type ())
#define PE_DFLIPFLOP_COMPONENT_STATE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PE_DFLIPFLOP_COMPONENT_STATE, PeDFlipflopComponentState))
#define PE_DFLIPFLOP_COMPONENT_STATE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PE_DFLIPFLOP_COMPONENT_STATE, PeDFlipflopComponentStateClass))
#define IS_PE_DFLIPFLOP_COMPONENT_STATE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PE_DFLIPFLOP_COMPONENT_STATE))
#define IS_PE_DFLIPFLOP_COMPONENT_STATE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PE_DFLIPFLOP_COMPONENT_STATE))
#define PE_DFLIPFLOP_COMPONENT_STATE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PE_DFLIPFLOP_COMPONENT_STATE, PeDFlipflopComponentStateClass))

typedef struct _PeDFlipflopComponentState PeDFlipflopComponentState;
typedef struct _PeDFlipflopComponentStateClass PeDFlipflopComponentStateClass;
typedef struct _PeDFlipflopComponentStatePrivate PeDFlipflopComponentStatePrivate;

#define TYPE_CONNECTION (connection_get_type ())
#define CONNECTION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_CONNECTION, Connection))
#define CONNECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_CONNECTION, ConnectionClass))
#define IS_CONNECTION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_CONNECTION))
#define IS_CONNECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_CONNECTION))
#define CONNECTION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_CONNECTION, ConnectionClass))

typedef struct _Connection Connection;
typedef struct _ConnectionClass ConnectionClass;
#define _connection_unref0(var) ((var == NULL) ? NULL : (var = (connection_unref (var), NULL)))
#define _component_inst_unref0(var) ((var == NULL) ? NULL : (var = (component_inst_unref (var), NULL)))

struct _ComponentState {
	GTypeInstance parent_instance;
	volatile int ref_count;
	ComponentStatePrivate * priv;
	CompiledCircuit* compiledCircuit;
	ComponentInst** ancestry;
	gint ancestry_length1;
	ComponentInst* componentInst;
	gint renderQueueID;
	gint processQueueID;
	gboolean display;
};

struct _ComponentStateClass {
	GTypeClass parent_class;
	void (*finalize) (ComponentState *self);
	void (*update) (ComponentState* self);
	void (*click) (ComponentState* self);
	void (*render) (ComponentState* self, cairo_t* context);
	gboolean (*get_alwaysUpdate) (ComponentState* self);
};

struct _PeDFlipflopComponentState {
	ComponentState parent_instance;
	PeDFlipflopComponentStatePrivate * priv;
};

struct _PeDFlipflopComponentStateClass {
	ComponentStateClass parent_class;
};

struct _PeDFlipflopComponentStatePrivate {
	Connection* dataWire;
	Connection* clockWire;
	Connection* outputWire;
	Connection* outputNotWire;
	gboolean output;
	gboolean previousClockSignal;
};


static gpointer pe_dflipflop_component_state_parent_class = NULL;

gpointer component_state_ref (gpointer instance);
void component_state_unref (gpointer instance);
GParamSpec* param_spec_component_state (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_component_state (GValue* value, gpointer v_object);
void value_take_component_state (GValue* value, gpointer v_object);
gpointer value_get_component_state (const GValue* value);
GType component_state_get_type (void) G_GNUC_CONST;
gpointer compiled_circuit_ref (gpointer instance);
void compiled_circuit_unref (gpointer instance);
GParamSpec* param_spec_compiled_circuit (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_compiled_circuit (GValue* value, gpointer v_object);
void value_take_compiled_circuit (GValue* value, gpointer v_object);
gpointer value_get_compiled_circuit (const GValue* value);
GType compiled_circuit_get_type (void) G_GNUC_CONST;
gpointer component_inst_ref (gpointer instance);
void component_inst_unref (gpointer instance);
GParamSpec* param_spec_component_inst (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_component_inst (GValue* value, gpointer v_object);
void value_take_component_inst (GValue* value, gpointer v_object);
gpointer value_get_component_inst (const GValue* value);
GType component_inst_get_type (void) G_GNUC_CONST;
GType pe_dflipflop_component_state_get_type (void) G_GNUC_CONST;
gpointer connection_ref (gpointer instance);
void connection_unref (gpointer instance);
GParamSpec* param_spec_connection (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_connection (GValue* value, gpointer v_object);
void value_take_connection (GValue* value, gpointer v_object);
gpointer value_get_connection (const GValue* value);
GType connection_get_type (void) G_GNUC_CONST;
#define PE_DFLIPFLOP_COMPONENT_STATE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_PE_DFLIPFLOP_COMPONENT_STATE, PeDFlipflopComponentStatePrivate))
enum  {
	PE_DFLIPFLOP_COMPONENT_STATE_DUMMY_PROPERTY
};
PeDFlipflopComponentState* pe_dflipflop_component_state_new (Connection* dataWire, Connection* clockWire, Connection* outputWire, Connection* outputNotWire, ComponentInst** ancestry, int ancestry_length1, ComponentInst* componentInst);
PeDFlipflopComponentState* pe_dflipflop_component_state_construct (GType object_type, Connection* dataWire, Connection* clockWire, Connection* outputWire, Connection* outputNotWire, ComponentInst** ancestry, int ancestry_length1, ComponentInst* componentInst);
ComponentState* component_state_construct (GType object_type);
void connection_set_affects (Connection* self, ComponentState* componentState);
static ComponentInst** _vala_array_dup33 (ComponentInst** self, int length);
static void pe_dflipflop_component_state_real_update (ComponentState* base);
gboolean connection_get_signalState (Connection* self);
void connection_set_signalState (Connection* self, gboolean value);
static void pe_dflipflop_component_state_finalize (ComponentState* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


static gpointer _connection_ref0 (gpointer self) {
	return self ? connection_ref (self) : NULL;
}


static gpointer _component_inst_ref0 (gpointer self) {
	return self ? component_inst_ref (self) : NULL;
}


static ComponentInst** _vala_array_dup33 (ComponentInst** self, int length) {
	ComponentInst** result;
	int i;
	result = g_new0 (ComponentInst*, length + 1);
	for (i = 0; i < length; i++) {
		ComponentInst* _tmp0_;
		_tmp0_ = _component_inst_ref0 (self[i]);
		result[i] = _tmp0_;
	}
	return result;
}


PeDFlipflopComponentState* pe_dflipflop_component_state_construct (GType object_type, Connection* dataWire, Connection* clockWire, Connection* outputWire, Connection* outputNotWire, ComponentInst** ancestry, int ancestry_length1, ComponentInst* componentInst) {
	PeDFlipflopComponentState* self = NULL;
	Connection* _tmp0_;
	Connection* _tmp1_;
	Connection* _tmp2_;
	Connection* _tmp3_;
	Connection* _tmp4_;
	Connection* _tmp5_;
	Connection* _tmp6_;
	Connection* _tmp7_;
	Connection* _tmp8_;
	ComponentInst** _tmp9_;
	gint _tmp9__length1;
	ComponentInst** _tmp10_;
	gint _tmp10__length1;
	ComponentInst* _tmp11_;
	ComponentInst* _tmp12_;
	g_return_val_if_fail (dataWire != NULL, NULL);
	g_return_val_if_fail (clockWire != NULL, NULL);
	g_return_val_if_fail (outputWire != NULL, NULL);
	g_return_val_if_fail (outputNotWire != NULL, NULL);
	g_return_val_if_fail (componentInst != NULL, NULL);
	self = (PeDFlipflopComponentState*) component_state_construct (object_type);
	_tmp0_ = dataWire;
	_tmp1_ = _connection_ref0 (_tmp0_);
	_connection_unref0 (self->priv->dataWire);
	self->priv->dataWire = _tmp1_;
	_tmp2_ = clockWire;
	_tmp3_ = _connection_ref0 (_tmp2_);
	_connection_unref0 (self->priv->clockWire);
	self->priv->clockWire = _tmp3_;
	_tmp4_ = clockWire;
	connection_set_affects (_tmp4_, (ComponentState*) self);
	_tmp5_ = outputWire;
	_tmp6_ = _connection_ref0 (_tmp5_);
	_connection_unref0 (self->priv->outputWire);
	self->priv->outputWire = _tmp6_;
	_tmp7_ = outputNotWire;
	_tmp8_ = _connection_ref0 (_tmp7_);
	_connection_unref0 (self->priv->outputNotWire);
	self->priv->outputNotWire = _tmp8_;
	self->priv->output = FALSE;
	self->priv->previousClockSignal = TRUE;
	_tmp9_ = ancestry;
	_tmp9__length1 = ancestry_length1;
	_tmp10_ = (_tmp9_ != NULL) ? _vala_array_dup33 (_tmp9_, _tmp9__length1) : ((gpointer) _tmp9_);
	_tmp10__length1 = _tmp9__length1;
	((ComponentState*) self)->ancestry = (_vala_array_free (((ComponentState*) self)->ancestry, ((ComponentState*) self)->ancestry_length1, (GDestroyNotify) component_inst_unref), NULL);
	((ComponentState*) self)->ancestry = _tmp10_;
	((ComponentState*) self)->ancestry_length1 = _tmp10__length1;
	_tmp11_ = componentInst;
	_tmp12_ = _component_inst_ref0 (_tmp11_);
	_component_inst_unref0 (((ComponentState*) self)->componentInst);
	((ComponentState*) self)->componentInst = _tmp12_;
	return self;
}


PeDFlipflopComponentState* pe_dflipflop_component_state_new (Connection* dataWire, Connection* clockWire, Connection* outputWire, Connection* outputNotWire, ComponentInst** ancestry, int ancestry_length1, ComponentInst* componentInst) {
	return pe_dflipflop_component_state_construct (TYPE_PE_DFLIPFLOP_COMPONENT_STATE, dataWire, clockWire, outputWire, outputNotWire, ancestry, ancestry_length1, componentInst);
}


static void pe_dflipflop_component_state_real_update (ComponentState* base) {
	PeDFlipflopComponentState * self;
	gboolean _tmp0_ = FALSE;
	Connection* _tmp1_;
	gboolean _tmp2_;
	gboolean _tmp3_;
	gboolean _tmp5_;
	Connection* _tmp9_;
	gboolean _tmp10_;
	gboolean _tmp11_;
	Connection* _tmp12_;
	gboolean _tmp13_;
	Connection* _tmp14_;
	gboolean _tmp15_;
	self = (PeDFlipflopComponentState*) base;
	_tmp1_ = self->priv->clockWire;
	_tmp2_ = connection_get_signalState (_tmp1_);
	_tmp3_ = _tmp2_;
	if (_tmp3_) {
		gboolean _tmp4_;
		_tmp4_ = self->priv->previousClockSignal;
		_tmp0_ = !_tmp4_;
	} else {
		_tmp0_ = FALSE;
	}
	_tmp5_ = _tmp0_;
	if (_tmp5_) {
		Connection* _tmp6_;
		gboolean _tmp7_;
		gboolean _tmp8_;
		_tmp6_ = self->priv->dataWire;
		_tmp7_ = connection_get_signalState (_tmp6_);
		_tmp8_ = _tmp7_;
		self->priv->output = _tmp8_;
	}
	_tmp9_ = self->priv->clockWire;
	_tmp10_ = connection_get_signalState (_tmp9_);
	_tmp11_ = _tmp10_;
	self->priv->previousClockSignal = _tmp11_;
	_tmp12_ = self->priv->outputWire;
	_tmp13_ = self->priv->output;
	connection_set_signalState (_tmp12_, _tmp13_);
	_tmp14_ = self->priv->outputNotWire;
	_tmp15_ = self->priv->output;
	connection_set_signalState (_tmp14_, !_tmp15_);
}


static void pe_dflipflop_component_state_class_init (PeDFlipflopComponentStateClass * klass) {
	pe_dflipflop_component_state_parent_class = g_type_class_peek_parent (klass);
	COMPONENT_STATE_CLASS (klass)->finalize = pe_dflipflop_component_state_finalize;
	g_type_class_add_private (klass, sizeof (PeDFlipflopComponentStatePrivate));
	COMPONENT_STATE_CLASS (klass)->update = pe_dflipflop_component_state_real_update;
}


static void pe_dflipflop_component_state_instance_init (PeDFlipflopComponentState * self) {
	self->priv = PE_DFLIPFLOP_COMPONENT_STATE_GET_PRIVATE (self);
}


static void pe_dflipflop_component_state_finalize (ComponentState* obj) {
	PeDFlipflopComponentState * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_PE_DFLIPFLOP_COMPONENT_STATE, PeDFlipflopComponentState);
	_connection_unref0 (self->priv->dataWire);
	_connection_unref0 (self->priv->clockWire);
	_connection_unref0 (self->priv->outputWire);
	_connection_unref0 (self->priv->outputNotWire);
	COMPONENT_STATE_CLASS (pe_dflipflop_component_state_parent_class)->finalize (obj);
}


GType pe_dflipflop_component_state_get_type (void) {
	static volatile gsize pe_dflipflop_component_state_type_id__volatile = 0;
	if (g_once_init_enter (&pe_dflipflop_component_state_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (PeDFlipflopComponentStateClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) pe_dflipflop_component_state_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (PeDFlipflopComponentState), 0, (GInstanceInitFunc) pe_dflipflop_component_state_instance_init, NULL };
		GType pe_dflipflop_component_state_type_id;
		pe_dflipflop_component_state_type_id = g_type_register_static (TYPE_COMPONENT_STATE, "PeDFlipflopComponentState", &g_define_type_info, 0);
		g_once_init_leave (&pe_dflipflop_component_state_type_id__volatile, pe_dflipflop_component_state_type_id);
	}
	return pe_dflipflop_component_state_type_id__volatile;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}



