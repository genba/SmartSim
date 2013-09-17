/* propertyitem-int.c generated by valac 0.20.1, the Vala compiler
 * generated from propertyitem-int.vala, do not modify */

/* 
 * SmartSim - Digital Logic Circuit Designer and Simulator
 *   
 *   Expansion Version
 *   
 *   Filename: propertyitem/int.vala
 *   
 *   Copyright Ashley Newson 2012
 */

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>


#define TYPE_PROPERTY_ITEM (property_item_get_type ())
#define PROPERTY_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PROPERTY_ITEM, PropertyItem))
#define PROPERTY_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PROPERTY_ITEM, PropertyItemClass))
#define IS_PROPERTY_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PROPERTY_ITEM))
#define IS_PROPERTY_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PROPERTY_ITEM))
#define PROPERTY_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PROPERTY_ITEM, PropertyItemClass))

typedef struct _PropertyItem PropertyItem;
typedef struct _PropertyItemClass PropertyItemClass;
typedef struct _PropertyItemPrivate PropertyItemPrivate;

#define TYPE_PROPERTY_ITEM_INT (property_item_int_get_type ())
#define PROPERTY_ITEM_INT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PROPERTY_ITEM_INT, PropertyItemInt))
#define PROPERTY_ITEM_INT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PROPERTY_ITEM_INT, PropertyItemIntClass))
#define IS_PROPERTY_ITEM_INT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PROPERTY_ITEM_INT))
#define IS_PROPERTY_ITEM_INT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PROPERTY_ITEM_INT))
#define PROPERTY_ITEM_INT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PROPERTY_ITEM_INT, PropertyItemIntClass))

typedef struct _PropertyItemInt PropertyItemInt;
typedef struct _PropertyItemIntClass PropertyItemIntClass;
typedef struct _PropertyItemIntPrivate PropertyItemIntPrivate;

#define TYPE_PROPERTY_SET (property_set_get_type ())
#define PROPERTY_SET(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PROPERTY_SET, PropertySet))
#define PROPERTY_SET_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PROPERTY_SET, PropertySetClass))
#define IS_PROPERTY_SET(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PROPERTY_SET))
#define IS_PROPERTY_SET_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PROPERTY_SET))
#define PROPERTY_SET_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PROPERTY_SET, PropertySetClass))

typedef struct _PropertySet PropertySet;
typedef struct _PropertySetClass PropertySetClass;
#define _property_item_unref0(var) ((var == NULL) ? NULL : (var = (property_item_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _PropertyItem {
	GTypeInstance parent_instance;
	volatile int ref_count;
	PropertyItemPrivate * priv;
	gchar* name;
	gchar* description;
};

struct _PropertyItemClass {
	GTypeClass parent_class;
	void (*finalize) (PropertyItem *self);
	GtkWidget* (*create_widget) (PropertyItem* self);
	void (*read_widget) (PropertyItem* self, GtkWidget* propertyWidget);
};

struct _PropertyItemInt {
	PropertyItem parent_instance;
	PropertyItemIntPrivate * priv;
	gint data;
};

struct _PropertyItemIntClass {
	PropertyItemClass parent_class;
};

typedef enum  {
	PROPERTY_ITEM_ERROR_ITEM_NOT_FOUND
} PropertyItemError;
#define PROPERTY_ITEM_ERROR property_item_error_quark ()

static gpointer property_item_int_parent_class = NULL;

gpointer property_item_ref (gpointer instance);
void property_item_unref (gpointer instance);
GParamSpec* param_spec_property_item (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_property_item (GValue* value, gpointer v_object);
void value_take_property_item (GValue* value, gpointer v_object);
gpointer value_get_property_item (const GValue* value);
GType property_item_get_type (void) G_GNUC_CONST;
GType property_item_int_get_type (void) G_GNUC_CONST;
enum  {
	PROPERTY_ITEM_INT_DUMMY_PROPERTY
};
GType property_set_get_type (void) G_GNUC_CONST;
GQuark property_item_error_quark (void);
gint property_item_int_get_data_throw (PropertySet* propertySet, const gchar* name, GError** error);
PropertyItem* property_set_get_item (PropertySet* self, const gchar* name);
void property_item_int_set_data_throw (PropertySet* propertySet, const gchar* name, gint data, GError** error);
gint property_item_int_get_data (PropertySet* propertySet, const gchar* name);
void property_item_int_set_data (PropertySet* propertySet, const gchar* name, gint data);
PropertyItemInt* property_item_int_new (const gchar* name, const gchar* description, gint data);
PropertyItemInt* property_item_int_construct (GType object_type, const gchar* name, const gchar* description, gint data);
PropertyItem* property_item_construct (GType object_type, const gchar* name, const gchar* description);
static GtkWidget* property_item_int_real_create_widget (PropertyItem* base);
static void property_item_int_real_read_widget (PropertyItem* base, GtkWidget* propertyWidget);
static void property_item_int_finalize (PropertyItem* obj);


gint property_item_int_get_data_throw (PropertySet* propertySet, const gchar* name, GError** error) {
	gint result = 0;
	PropertySet* _tmp0_;
	const gchar* _tmp1_;
	PropertyItem* _tmp2_ = NULL;
	PropertyItem* propertyItem;
	PropertyItem* _tmp3_;
	PropertySet* _tmp7_;
	const gchar* _tmp8_;
	gchar* _tmp9_;
	gchar* _tmp10_;
	gchar* _tmp11_;
	gchar* _tmp12_;
	const gchar* _tmp13_;
	gchar* _tmp14_;
	gchar* _tmp15_;
	gchar* _tmp16_;
	gchar* _tmp17_;
	GError* _tmp18_;
	GError* _tmp19_;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (propertySet != NULL, 0);
	g_return_val_if_fail (name != NULL, 0);
	_tmp0_ = propertySet;
	_tmp1_ = name;
	_tmp2_ = property_set_get_item (_tmp0_, _tmp1_);
	propertyItem = _tmp2_;
	_tmp3_ = propertyItem;
	if (_tmp3_ != NULL) {
		PropertyItem* _tmp4_;
		_tmp4_ = propertyItem;
		if (G_TYPE_CHECK_INSTANCE_TYPE (_tmp4_, TYPE_PROPERTY_ITEM_INT)) {
			PropertyItem* _tmp5_;
			gint _tmp6_;
			_tmp5_ = propertyItem;
			_tmp6_ = (G_TYPE_CHECK_INSTANCE_TYPE (_tmp5_, TYPE_PROPERTY_ITEM_INT) ? ((PropertyItemInt*) _tmp5_) : NULL)->data;
			result = _tmp6_;
			_property_item_unref0 (propertyItem);
			return result;
		}
	}
	_tmp7_ = propertySet;
	_tmp8_ = ((PropertyItem*) _tmp7_)->name;
	_tmp9_ = g_strconcat ("\"", _tmp8_, NULL);
	_tmp10_ = _tmp9_;
	_tmp11_ = g_strconcat (_tmp10_, "\" does not contain an int named \"", NULL);
	_tmp12_ = _tmp11_;
	_tmp13_ = name;
	_tmp14_ = g_strconcat (_tmp12_, _tmp13_, NULL);
	_tmp15_ = _tmp14_;
	_tmp16_ = g_strconcat (_tmp15_, "\"", NULL);
	_tmp17_ = _tmp16_;
	_tmp18_ = g_error_new_literal (PROPERTY_ITEM_ERROR, PROPERTY_ITEM_ERROR_ITEM_NOT_FOUND, _tmp17_);
	_tmp19_ = _tmp18_;
	_g_free0 (_tmp17_);
	_g_free0 (_tmp15_);
	_g_free0 (_tmp12_);
	_g_free0 (_tmp10_);
	_inner_error_ = _tmp19_;
	if (_inner_error_->domain == PROPERTY_ITEM_ERROR) {
		g_propagate_error (error, _inner_error_);
		_property_item_unref0 (propertyItem);
		return 0;
	} else {
		_property_item_unref0 (propertyItem);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return 0;
	}
	_property_item_unref0 (propertyItem);
}


void property_item_int_set_data_throw (PropertySet* propertySet, const gchar* name, gint data, GError** error) {
	PropertySet* _tmp0_;
	const gchar* _tmp1_;
	PropertyItem* _tmp2_ = NULL;
	PropertyItem* propertyItem;
	PropertyItem* _tmp3_;
	PropertySet* _tmp7_;
	const gchar* _tmp8_;
	gchar* _tmp9_;
	gchar* _tmp10_;
	gchar* _tmp11_;
	gchar* _tmp12_;
	const gchar* _tmp13_;
	gchar* _tmp14_;
	gchar* _tmp15_;
	gchar* _tmp16_;
	gchar* _tmp17_;
	GError* _tmp18_;
	GError* _tmp19_;
	GError * _inner_error_ = NULL;
	g_return_if_fail (propertySet != NULL);
	g_return_if_fail (name != NULL);
	_tmp0_ = propertySet;
	_tmp1_ = name;
	_tmp2_ = property_set_get_item (_tmp0_, _tmp1_);
	propertyItem = _tmp2_;
	_tmp3_ = propertyItem;
	if (_tmp3_ != NULL) {
		PropertyItem* _tmp4_;
		_tmp4_ = propertyItem;
		if (G_TYPE_CHECK_INSTANCE_TYPE (_tmp4_, TYPE_PROPERTY_ITEM_INT)) {
			PropertyItem* _tmp5_;
			gint _tmp6_;
			_tmp5_ = propertyItem;
			_tmp6_ = data;
			(G_TYPE_CHECK_INSTANCE_TYPE (_tmp5_, TYPE_PROPERTY_ITEM_INT) ? ((PropertyItemInt*) _tmp5_) : NULL)->data = _tmp6_;
			_property_item_unref0 (propertyItem);
			return;
		}
	}
	_tmp7_ = propertySet;
	_tmp8_ = ((PropertyItem*) _tmp7_)->name;
	_tmp9_ = g_strconcat ("\"", _tmp8_, NULL);
	_tmp10_ = _tmp9_;
	_tmp11_ = g_strconcat (_tmp10_, "\" does not contain an int named \"", NULL);
	_tmp12_ = _tmp11_;
	_tmp13_ = name;
	_tmp14_ = g_strconcat (_tmp12_, _tmp13_, NULL);
	_tmp15_ = _tmp14_;
	_tmp16_ = g_strconcat (_tmp15_, "\"", NULL);
	_tmp17_ = _tmp16_;
	_tmp18_ = g_error_new_literal (PROPERTY_ITEM_ERROR, PROPERTY_ITEM_ERROR_ITEM_NOT_FOUND, _tmp17_);
	_tmp19_ = _tmp18_;
	_g_free0 (_tmp17_);
	_g_free0 (_tmp15_);
	_g_free0 (_tmp12_);
	_g_free0 (_tmp10_);
	_inner_error_ = _tmp19_;
	if (_inner_error_->domain == PROPERTY_ITEM_ERROR) {
		g_propagate_error (error, _inner_error_);
		_property_item_unref0 (propertyItem);
		return;
	} else {
		_property_item_unref0 (propertyItem);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_property_item_unref0 (propertyItem);
}


gint property_item_int_get_data (PropertySet* propertySet, const gchar* name) {
	gint result = 0;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (propertySet != NULL, 0);
	g_return_val_if_fail (name != NULL, 0);
	{
		PropertySet* _tmp0_;
		const gchar* _tmp1_;
		gint _tmp2_ = 0;
		gint _tmp3_;
		_tmp0_ = propertySet;
		_tmp1_ = name;
		_tmp2_ = property_item_int_get_data_throw (_tmp0_, _tmp1_, &_inner_error_);
		_tmp3_ = _tmp2_;
		if (_inner_error_ != NULL) {
			goto __catch61_g_error;
		}
		result = _tmp3_;
		return result;
	}
	goto __finally61;
	__catch61_g_error:
	{
		g_clear_error (&_inner_error_);
		_inner_error_ = NULL;
		result = 0;
		return result;
	}
	__finally61:
	g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
	g_clear_error (&_inner_error_);
	return 0;
}


void property_item_int_set_data (PropertySet* propertySet, const gchar* name, gint data) {
	GError * _inner_error_ = NULL;
	g_return_if_fail (propertySet != NULL);
	g_return_if_fail (name != NULL);
	{
		PropertySet* _tmp0_;
		const gchar* _tmp1_;
		gint _tmp2_;
		_tmp0_ = propertySet;
		_tmp1_ = name;
		_tmp2_ = data;
		property_item_int_set_data_throw (_tmp0_, _tmp1_, _tmp2_, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch62_g_error;
		}
	}
	goto __finally62;
	__catch62_g_error:
	{
		g_clear_error (&_inner_error_);
		_inner_error_ = NULL;
	}
	__finally62:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


PropertyItemInt* property_item_int_construct (GType object_type, const gchar* name, const gchar* description, gint data) {
	PropertyItemInt* self = NULL;
	const gchar* _tmp0_;
	const gchar* _tmp1_;
	gint _tmp2_;
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (description != NULL, NULL);
	_tmp0_ = name;
	_tmp1_ = description;
	self = (PropertyItemInt*) property_item_construct (object_type, _tmp0_, _tmp1_);
	_tmp2_ = data;
	self->data = _tmp2_;
	return self;
}


PropertyItemInt* property_item_int_new (const gchar* name, const gchar* description, gint data) {
	return property_item_int_construct (TYPE_PROPERTY_ITEM_INT, name, description, data);
}


static GtkWidget* property_item_int_real_create_widget (PropertyItem* base) {
	PropertyItemInt * self;
	GtkWidget* result = NULL;
	gint _tmp0_;
	gint _tmp1_;
	GtkSpinButton* _tmp2_;
	GtkSpinButton* intSpinButton;
	gint _tmp3_;
	self = (PropertyItemInt*) base;
	_tmp0_ = G_MININT;
	_tmp1_ = G_MAXINT;
	_tmp2_ = (GtkSpinButton*) gtk_spin_button_new_with_range ((gdouble) _tmp0_, (gdouble) _tmp1_, (gdouble) 1);
	g_object_ref_sink (_tmp2_);
	intSpinButton = _tmp2_;
	_tmp3_ = self->data;
	gtk_spin_button_set_value (intSpinButton, (gdouble) _tmp3_);
	result = (GtkWidget*) intSpinButton;
	return result;
}


static void property_item_int_real_read_widget (PropertyItem* base, GtkWidget* propertyWidget) {
	PropertyItemInt * self;
	GtkWidget* _tmp0_;
	self = (PropertyItemInt*) base;
	g_return_if_fail (propertyWidget != NULL);
	_tmp0_ = propertyWidget;
	if (_tmp0_ != NULL) {
		GtkWidget* _tmp1_;
		_tmp1_ = propertyWidget;
		if (G_TYPE_CHECK_INSTANCE_TYPE (_tmp1_, GTK_TYPE_SPIN_BUTTON)) {
			GtkWidget* _tmp2_;
			gint _tmp3_ = 0;
			_tmp2_ = propertyWidget;
			_tmp3_ = gtk_spin_button_get_value_as_int (G_TYPE_CHECK_INSTANCE_TYPE (_tmp2_, GTK_TYPE_SPIN_BUTTON) ? ((GtkSpinButton*) _tmp2_) : NULL);
			self->data = _tmp3_;
		}
	}
}


static void property_item_int_class_init (PropertyItemIntClass * klass) {
	property_item_int_parent_class = g_type_class_peek_parent (klass);
	PROPERTY_ITEM_CLASS (klass)->finalize = property_item_int_finalize;
	PROPERTY_ITEM_CLASS (klass)->create_widget = property_item_int_real_create_widget;
	PROPERTY_ITEM_CLASS (klass)->read_widget = property_item_int_real_read_widget;
}


static void property_item_int_instance_init (PropertyItemInt * self) {
}


static void property_item_int_finalize (PropertyItem* obj) {
	PropertyItemInt * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_PROPERTY_ITEM_INT, PropertyItemInt);
	PROPERTY_ITEM_CLASS (property_item_int_parent_class)->finalize (obj);
}


GType property_item_int_get_type (void) {
	static volatile gsize property_item_int_type_id__volatile = 0;
	if (g_once_init_enter (&property_item_int_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (PropertyItemIntClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) property_item_int_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (PropertyItemInt), 0, (GInstanceInitFunc) property_item_int_instance_init, NULL };
		GType property_item_int_type_id;
		property_item_int_type_id = g_type_register_static (TYPE_PROPERTY_ITEM, "PropertyItemInt", &g_define_type_info, 0);
		g_once_init_leave (&property_item_int_type_id__volatile, property_item_int_type_id);
	}
	return property_item_int_type_id__volatile;
}



