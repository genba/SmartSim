/* graphic.c generated by valac 0.18.1, the Vala compiler
 * generated from graphic.vala, do not modify */

/* 
 * SmartSim - Digital Logic Circuit Designer and Simulator
 *   
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *   
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *   
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *   
 *   Filename: graphic.vala
 *   
 *   Copyright Ashley Newson 2013
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <librsvg/rsvg.h>
#include <stdio.h>
#include <libxml/tree.h>
#include <libxml/parser.h>
#include <cairo.h>
#include <float.h>
#include <math.h>
#include <gobject/gvaluecollector.h>


#define TYPE_GRAPHIC (graphic_get_type ())
#define GRAPHIC(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_GRAPHIC, Graphic))
#define GRAPHIC_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_GRAPHIC, GraphicClass))
#define IS_GRAPHIC(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_GRAPHIC))
#define IS_GRAPHIC_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_GRAPHIC))
#define GRAPHIC_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_GRAPHIC, GraphicClass))

typedef struct _Graphic Graphic;
typedef struct _GraphicClass GraphicClass;
typedef struct _GraphicPrivate GraphicPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _graphic_unref0(var) ((var == NULL) ? NULL : (var = (graphic_unref (var), NULL)))
typedef struct _ParamSpecGraphic ParamSpecGraphic;

typedef enum  {
	GRAPHIC_LOAD_ERROR_FILE
} GraphicLoadError;
#define GRAPHIC_LOAD_ERROR graphic_load_error_quark ()
struct _Graphic {
	GTypeInstance parent_instance;
	volatile int ref_count;
	GraphicPrivate * priv;
	gchar* filename;
	gchar* svgFilename;
	gchar* infoFilename;
};

struct _GraphicClass {
	GTypeClass parent_class;
	void (*finalize) (Graphic *self);
};

struct _GraphicPrivate {
	RsvgHandle* svgHandle;
	gint width;
	gint height;
	gint xCentre;
	gint yCentre;
};

struct _ParamSpecGraphic {
	GParamSpec parent_instance;
};


static gpointer graphic_parent_class = NULL;
extern Graphic* graphic_placeHolder;
Graphic* graphic_placeHolder = NULL;

GQuark graphic_load_error_quark (void);
gpointer graphic_ref (gpointer instance);
void graphic_unref (gpointer instance);
GParamSpec* param_spec_graphic (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void value_set_graphic (GValue* value, gpointer v_object);
void value_take_graphic (GValue* value, gpointer v_object);
gpointer value_get_graphic (const GValue* value);
GType graphic_get_type (void) G_GNUC_CONST;
#define GRAPHIC_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_GRAPHIC, GraphicPrivate))
enum  {
	GRAPHIC_DUMMY_PROPERTY
};
Graphic* graphic_new_from_file (const gchar* filename, GError** error);
Graphic* graphic_construct_from_file (GType object_type, const gchar* filename, GError** error);
gint graphic_load_info (Graphic* self, const gchar* filename);
gint graphic_load_svg (Graphic* self, const gchar* filename);
void graphic_render (Graphic* self, cairo_t* context);
Graphic* graphic_new (void);
Graphic* graphic_construct (GType object_type);
static void graphic_finalize (Graphic* obj);


GQuark graphic_load_error_quark (void) {
	return g_quark_from_static_string ("graphic_load_error-quark");
}


/**
 * Loads a graphic from the files //filename//.info and
 * //filename//.svg.
 */
Graphic* graphic_construct_from_file (GType object_type, const gchar* filename, GError** error) {
	Graphic* self = NULL;
	FILE* _tmp0_;
	const gchar* _tmp1_;
	const gchar* _tmp2_;
	gchar* _tmp3_;
	const gchar* _tmp4_;
	gchar* _tmp5_;
	gchar* _tmp6_;
	gint _tmp7_ = 0;
	gboolean _tmp8_;
	const gchar* _tmp16_;
	gchar* _tmp17_;
	gchar* _tmp18_;
	gint _tmp19_ = 0;
	gboolean _tmp20_;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (filename != NULL, NULL);
	self = (Graphic*) g_type_create_instance (object_type);
	_tmp0_ = stdout;
	_tmp1_ = filename;
	fprintf (_tmp0_, "Loading graphic \"%s\"\n", _tmp1_);
	_tmp2_ = filename;
	_tmp3_ = g_strdup (_tmp2_);
	_g_free0 (self->filename);
	self->filename = _tmp3_;
	_tmp4_ = filename;
	_tmp5_ = g_strconcat (_tmp4_, ".info", NULL);
	_tmp6_ = _tmp5_;
	_tmp7_ = graphic_load_info (self, _tmp6_);
	_tmp8_ = _tmp7_ != 0;
	_g_free0 (_tmp6_);
	if (_tmp8_) {
		const gchar* _tmp9_;
		gchar* _tmp10_;
		gchar* _tmp11_;
		gchar* _tmp12_;
		gchar* _tmp13_;
		GError* _tmp14_;
		GError* _tmp15_;
		_tmp9_ = filename;
		_tmp10_ = g_strconcat ("Unable to open graphic file \"", _tmp9_, NULL);
		_tmp11_ = _tmp10_;
		_tmp12_ = g_strconcat (_tmp11_, ".info\".", NULL);
		_tmp13_ = _tmp12_;
		_tmp14_ = g_error_new_literal (GRAPHIC_LOAD_ERROR, GRAPHIC_LOAD_ERROR_FILE, _tmp13_);
		_tmp15_ = _tmp14_;
		_g_free0 (_tmp13_);
		_g_free0 (_tmp11_);
		_inner_error_ = _tmp15_;
		if (_inner_error_->domain == GRAPHIC_LOAD_ERROR) {
			g_propagate_error (error, _inner_error_);
			_graphic_unref0 (self);
			return NULL;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	}
	_tmp16_ = filename;
	_tmp17_ = g_strconcat (_tmp16_, ".svg", NULL);
	_tmp18_ = _tmp17_;
	_tmp19_ = graphic_load_svg (self, _tmp18_);
	_tmp20_ = _tmp19_ != 0;
	_g_free0 (_tmp18_);
	if (_tmp20_) {
		const gchar* _tmp21_;
		gchar* _tmp22_;
		gchar* _tmp23_;
		gchar* _tmp24_;
		gchar* _tmp25_;
		GError* _tmp26_;
		GError* _tmp27_;
		_tmp21_ = filename;
		_tmp22_ = g_strconcat ("Unable to open svg file \"", _tmp21_, NULL);
		_tmp23_ = _tmp22_;
		_tmp24_ = g_strconcat (_tmp23_, ".svg\".", NULL);
		_tmp25_ = _tmp24_;
		_tmp26_ = g_error_new_literal (GRAPHIC_LOAD_ERROR, GRAPHIC_LOAD_ERROR_FILE, _tmp25_);
		_tmp27_ = _tmp26_;
		_g_free0 (_tmp25_);
		_g_free0 (_tmp23_);
		_inner_error_ = _tmp27_;
		if (_inner_error_->domain == GRAPHIC_LOAD_ERROR) {
			g_propagate_error (error, _inner_error_);
			_graphic_unref0 (self);
			return NULL;
		} else {
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	}
	return self;
}


Graphic* graphic_new_from_file (const gchar* filename, GError** error) {
	return graphic_construct_from_file (TYPE_GRAPHIC, filename, error);
}


/**
 * Reads an info file, which describes how to use the svg image
 * (describing its centre, width...).
 */
gint graphic_load_info (Graphic* self, const gchar* filename) {
	gint result = 0;
	FILE* _tmp0_;
	const gchar* _tmp1_;
	const gchar* _tmp2_;
	gchar* _tmp3_;
	xmlDoc* xmldoc = NULL;
	xmlNode* xmlroot = NULL;
	xmlNode* xmlnode = NULL;
	const gchar* _tmp4_;
	xmlDoc* _tmp5_ = NULL;
	xmlDoc* _tmp6_;
	xmlDoc* _tmp10_;
	xmlNode* _tmp11_ = NULL;
	xmlNode* _tmp12_;
	xmlNode* _tmp16_;
	const gchar* _tmp17_;
	xmlDoc* _tmp75_;
	g_return_val_if_fail (self != NULL, 0);
	g_return_val_if_fail (filename != NULL, 0);
	_tmp0_ = stdout;
	_tmp1_ = filename;
	fprintf (_tmp0_, "Loading graphic info \"%s\"\n", _tmp1_);
	_tmp2_ = filename;
	_tmp3_ = g_strdup (_tmp2_);
	_g_free0 (self->infoFilename);
	self->infoFilename = _tmp3_;
	_tmp4_ = filename;
	_tmp5_ = xmlParseFile (_tmp4_);
	xmldoc = _tmp5_;
	_tmp6_ = xmldoc;
	if (_tmp6_ == NULL) {
		FILE* _tmp7_;
		const gchar* _tmp8_;
		FILE* _tmp9_;
		_tmp7_ = stdout;
		_tmp8_ = filename;
		fprintf (_tmp7_, "Error loading info xml file \"%s\".\n", _tmp8_);
		_tmp9_ = stdout;
		fprintf (_tmp9_, "File inaccessible.\n");
		result = 1;
		return result;
	}
	_tmp10_ = xmldoc;
	_tmp11_ = xmlDocGetRootElement (_tmp10_);
	xmlroot = _tmp11_;
	_tmp12_ = xmlroot;
	if (_tmp12_ == NULL) {
		FILE* _tmp13_;
		const gchar* _tmp14_;
		FILE* _tmp15_;
		_tmp13_ = stdout;
		_tmp14_ = filename;
		fprintf (_tmp13_, "Error loading info xml file \"%s\".\n", _tmp14_);
		_tmp15_ = stdout;
		fprintf (_tmp15_, "File is empty.\n");
		result = 2;
		return result;
	}
	_tmp16_ = xmlroot;
	_tmp17_ = _tmp16_->name;
	if (g_strcmp0 (_tmp17_, "graphic_info") != 0) {
		FILE* _tmp18_;
		const gchar* _tmp19_;
		FILE* _tmp20_;
		xmlNode* _tmp21_;
		const gchar* _tmp22_;
		_tmp18_ = stdout;
		_tmp19_ = filename;
		fprintf (_tmp18_, "Error loading info xml file \"%s\".\n", _tmp19_);
		_tmp20_ = stdout;
		_tmp21_ = xmlroot;
		_tmp22_ = _tmp21_->name;
		fprintf (_tmp20_, "Wanted \"graphic_info\" info, but got \"%s\"\n", _tmp22_);
		result = 3;
		return result;
	}
	{
		xmlNode* _tmp23_;
		xmlNode* _tmp24_;
		gboolean _tmp25_;
		_tmp23_ = xmlroot;
		_tmp24_ = _tmp23_->children;
		xmlnode = _tmp24_;
		_tmp25_ = TRUE;
		while (TRUE) {
			gboolean _tmp26_;
			xmlNode* _tmp29_;
			xmlNode* _tmp30_;
			xmlElementType _tmp31_;
			xmlNode* _tmp32_;
			const gchar* _tmp33_;
			const gchar* _tmp34_;
			GQuark _tmp36_ = 0U;
			static GQuark _tmp35_label0 = 0;
			static GQuark _tmp35_label1 = 0;
			static GQuark _tmp35_label2 = 0;
			_tmp26_ = _tmp25_;
			if (!_tmp26_) {
				xmlNode* _tmp27_;
				xmlNode* _tmp28_;
				_tmp27_ = xmlnode;
				_tmp28_ = _tmp27_->next;
				xmlnode = _tmp28_;
			}
			_tmp25_ = FALSE;
			_tmp29_ = xmlnode;
			if (!(_tmp29_ != NULL)) {
				break;
			}
			_tmp30_ = xmlnode;
			_tmp31_ = _tmp30_->type;
			if (_tmp31_ != XML_ELEMENT_NODE) {
				continue;
			}
			_tmp32_ = xmlnode;
			_tmp33_ = _tmp32_->name;
			_tmp34_ = _tmp33_;
			_tmp36_ = (NULL == _tmp34_) ? 0 : g_quark_from_string (_tmp34_);
			if ((_tmp36_ == ((0 != _tmp35_label0) ? _tmp35_label0 : (_tmp35_label0 = g_quark_from_static_string ("centre")))) || (_tmp36_ == ((0 != _tmp35_label1) ? _tmp35_label1 : (_tmp35_label1 = g_quark_from_static_string ("center"))))) {
				switch (0) {
					default:
					{
						{
							{
								xmlNode* _tmp37_;
								xmlAttr* _tmp38_;
								xmlAttr* xmlattr;
								_tmp37_ = xmlnode;
								_tmp38_ = _tmp37_->properties;
								xmlattr = _tmp38_;
								{
									gboolean _tmp39_;
									_tmp39_ = TRUE;
									while (TRUE) {
										gboolean _tmp40_;
										xmlAttr* _tmp43_;
										xmlAttr* _tmp44_;
										const gchar* _tmp45_;
										xmlAttr* _tmp50_;
										const gchar* _tmp51_;
										_tmp40_ = _tmp39_;
										if (!_tmp40_) {
											xmlAttr* _tmp41_;
											xmlAttr* _tmp42_;
											_tmp41_ = xmlattr;
											_tmp42_ = _tmp41_->next;
											xmlattr = _tmp42_;
										}
										_tmp39_ = FALSE;
										_tmp43_ = xmlattr;
										if (!(_tmp43_ != NULL)) {
											break;
										}
										_tmp44_ = xmlattr;
										_tmp45_ = _tmp44_->name;
										if (g_strcmp0 (_tmp45_, "x") == 0) {
											xmlAttr* _tmp46_;
											xmlNode* _tmp47_;
											const gchar* _tmp48_;
											gint _tmp49_ = 0;
											_tmp46_ = xmlattr;
											_tmp47_ = _tmp46_->children;
											_tmp48_ = _tmp47_->content;
											_tmp49_ = atoi (_tmp48_);
											self->priv->xCentre = _tmp49_;
										}
										_tmp50_ = xmlattr;
										_tmp51_ = _tmp50_->name;
										if (g_strcmp0 (_tmp51_, "y") == 0) {
											xmlAttr* _tmp52_;
											xmlNode* _tmp53_;
											const gchar* _tmp54_;
											gint _tmp55_ = 0;
											_tmp52_ = xmlattr;
											_tmp53_ = _tmp52_->children;
											_tmp54_ = _tmp53_->content;
											_tmp55_ = atoi (_tmp54_);
											self->priv->yCentre = _tmp55_;
										}
									}
								}
							}
						}
						break;
					}
				}
			} else if (_tmp36_ == ((0 != _tmp35_label2) ? _tmp35_label2 : (_tmp35_label2 = g_quark_from_static_string ("size")))) {
				switch (0) {
					default:
					{
						{
							{
								xmlNode* _tmp56_;
								xmlAttr* _tmp57_;
								xmlAttr* xmlattr;
								_tmp56_ = xmlnode;
								_tmp57_ = _tmp56_->properties;
								xmlattr = _tmp57_;
								{
									gboolean _tmp58_;
									_tmp58_ = TRUE;
									while (TRUE) {
										gboolean _tmp59_;
										xmlAttr* _tmp62_;
										xmlAttr* _tmp63_;
										const gchar* _tmp64_;
										xmlAttr* _tmp69_;
										const gchar* _tmp70_;
										_tmp59_ = _tmp58_;
										if (!_tmp59_) {
											xmlAttr* _tmp60_;
											xmlAttr* _tmp61_;
											_tmp60_ = xmlattr;
											_tmp61_ = _tmp60_->next;
											xmlattr = _tmp61_;
										}
										_tmp58_ = FALSE;
										_tmp62_ = xmlattr;
										if (!(_tmp62_ != NULL)) {
											break;
										}
										_tmp63_ = xmlattr;
										_tmp64_ = _tmp63_->name;
										if (g_strcmp0 (_tmp64_, "width") == 0) {
											xmlAttr* _tmp65_;
											xmlNode* _tmp66_;
											const gchar* _tmp67_;
											gint _tmp68_ = 0;
											_tmp65_ = xmlattr;
											_tmp66_ = _tmp65_->children;
											_tmp67_ = _tmp66_->content;
											_tmp68_ = atoi (_tmp67_);
											self->priv->height = _tmp68_;
										}
										_tmp69_ = xmlattr;
										_tmp70_ = _tmp69_->name;
										if (g_strcmp0 (_tmp70_, "height") == 0) {
											xmlAttr* _tmp71_;
											xmlNode* _tmp72_;
											const gchar* _tmp73_;
											gint _tmp74_ = 0;
											_tmp71_ = xmlattr;
											_tmp72_ = _tmp71_->children;
											_tmp73_ = _tmp72_->content;
											_tmp74_ = atoi (_tmp73_);
											self->priv->width = _tmp74_;
										}
									}
								}
							}
						}
						break;
					}
				}
			}
		}
	}
	_tmp75_ = xmldoc;
	xmlFreeDoc (_tmp75_);
	result = 0;
	return result;
}


/**
 * Loads the SVG using librsvg.
 */
gint graphic_load_svg (Graphic* self, const gchar* filename) {
	gint result = 0;
	FILE* _tmp0_;
	const gchar* _tmp1_;
	const gchar* _tmp2_;
	gchar* _tmp3_;
	RsvgHandle* _tmp9_;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (self != NULL, 0);
	g_return_val_if_fail (filename != NULL, 0);
	_tmp0_ = stdout;
	_tmp1_ = filename;
	fprintf (_tmp0_, "Loading svg \"%s\"\n", _tmp1_);
	_tmp2_ = filename;
	_tmp3_ = g_strdup (_tmp2_);
	_g_free0 (self->svgFilename);
	self->svgFilename = _tmp3_;
	{
		const gchar* _tmp4_;
		RsvgHandle* _tmp5_;
		RsvgHandle* _tmp6_;
		_tmp4_ = filename;
		_tmp5_ = rsvg_handle_new_from_file (_tmp4_, &_inner_error_);
		_tmp6_ = _tmp5_;
		if (_inner_error_ != NULL) {
			goto __catch53_g_error;
		}
		_g_object_unref0 (self->priv->svgHandle);
		self->priv->svgHandle = _tmp6_;
	}
	goto __finally53;
	__catch53_g_error:
	{
		FILE* _tmp7_;
		const gchar* _tmp8_;
		g_clear_error (&_inner_error_);
		_inner_error_ = NULL;
		_tmp7_ = stdout;
		_tmp8_ = filename;
		fprintf (_tmp7_, "Error loading graphic \"%s\"\n", _tmp8_);
		result = 1;
		return result;
	}
	__finally53:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return 0;
	}
	_tmp9_ = self->priv->svgHandle;
	if (_tmp9_ == NULL) {
		FILE* _tmp10_;
		const gchar* _tmp11_;
		_tmp10_ = stdout;
		_tmp11_ = filename;
		fprintf (_tmp10_, "Error loading graphic \"%s\"\n", _tmp11_);
		result = 2;
		return result;
	}
	result = 0;
	return result;
}


/**
 * Renders the SVG, performing any necessary transformations.
 */
void graphic_render (Graphic* self, cairo_t* context) {
	cairo_matrix_t oldmatrix = {0};
	cairo_t* _tmp0_;
	cairo_matrix_t _tmp1_ = {0};
	cairo_t* _tmp2_;
	gint _tmp3_;
	gint _tmp4_;
	RsvgHandle* _tmp5_;
	cairo_t* _tmp6_;
	cairo_t* _tmp7_;
	cairo_matrix_t _tmp8_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (context != NULL);
	_tmp0_ = context;
	cairo_get_matrix (_tmp0_, &_tmp1_);
	oldmatrix = _tmp1_;
	_tmp2_ = context;
	_tmp3_ = self->priv->xCentre;
	_tmp4_ = self->priv->yCentre;
	cairo_translate (_tmp2_, (gdouble) (-_tmp3_), (gdouble) (-_tmp4_));
	_tmp5_ = self->priv->svgHandle;
	_tmp6_ = context;
	rsvg_handle_render_cairo (_tmp5_, _tmp6_);
	_tmp7_ = context;
	_tmp8_ = oldmatrix;
	cairo_set_matrix (_tmp7_, &_tmp8_);
}


Graphic* graphic_construct (GType object_type) {
	Graphic* self = NULL;
	self = (Graphic*) g_type_create_instance (object_type);
	return self;
}


Graphic* graphic_new (void) {
	return graphic_construct (TYPE_GRAPHIC);
}


static void value_graphic_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void value_graphic_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		graphic_unref (value->data[0].v_pointer);
	}
}


static void value_graphic_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = graphic_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer value_graphic_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* value_graphic_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		Graphic* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = graphic_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* value_graphic_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	Graphic** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = graphic_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* param_spec_graphic (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	ParamSpecGraphic* spec;
	g_return_val_if_fail (g_type_is_a (object_type, TYPE_GRAPHIC), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer value_get_graphic (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_GRAPHIC), NULL);
	return value->data[0].v_pointer;
}


void value_set_graphic (GValue* value, gpointer v_object) {
	Graphic* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_GRAPHIC));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_GRAPHIC));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		graphic_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		graphic_unref (old);
	}
}


void value_take_graphic (GValue* value, gpointer v_object) {
	Graphic* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, TYPE_GRAPHIC));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, TYPE_GRAPHIC));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		graphic_unref (old);
	}
}


static void graphic_class_init (GraphicClass * klass) {
	graphic_parent_class = g_type_class_peek_parent (klass);
	GRAPHIC_CLASS (klass)->finalize = graphic_finalize;
	g_type_class_add_private (klass, sizeof (GraphicPrivate));
}


static void graphic_instance_init (Graphic * self) {
	self->priv = GRAPHIC_GET_PRIVATE (self);
	self->ref_count = 1;
}


static void graphic_finalize (Graphic* obj) {
	Graphic * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_GRAPHIC, Graphic);
	_g_object_unref0 (self->priv->svgHandle);
	_g_free0 (self->filename);
	_g_free0 (self->svgFilename);
	_g_free0 (self->infoFilename);
}


/**
 * Used to store and render an SVG image.
 */
GType graphic_get_type (void) {
	static volatile gsize graphic_type_id__volatile = 0;
	if (g_once_init_enter (&graphic_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { value_graphic_init, value_graphic_free_value, value_graphic_copy_value, value_graphic_peek_pointer, "p", value_graphic_collect_value, "p", value_graphic_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (GraphicClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) graphic_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Graphic), 0, (GInstanceInitFunc) graphic_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType graphic_type_id;
		graphic_type_id = g_type_register_fundamental (g_type_fundamental_next (), "Graphic", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&graphic_type_id__volatile, graphic_type_id);
	}
	return graphic_type_id__volatile;
}


gpointer graphic_ref (gpointer instance) {
	Graphic* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void graphic_unref (gpointer instance) {
	Graphic* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		GRAPHIC_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}



