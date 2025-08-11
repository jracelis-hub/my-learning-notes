# CSS ( Cascade Style Sheet)

# Introduction 

CSS or _Cascade Style Sheet_ is used to style and change the appearance of HTML files. 

There are 3 types of ways to add CSS to a HTML file:

1. Inline - using style inside a HTML element `< h1 style="">`
2. Internal - adding style in `<head>style="item"</head>` 
3. External - adding the stylesheet in the HTML file `<head><link rel="stylesheet" href="style.css"/></head>`

There are serveral properties in CSS. 

For sizing there is absolute units and relative units:

- Absolute units means it is related to another property. Parent vs Child
- Relative units means no what type of environment it is in it conforms to that. 

Types of Relative Units:

- `%`
- `em` - em is relative to the font size of parent element
- `rem` - root is relative to the root `<html>`
- `vw`
- `vh` 

Types of Absolute Units:

- `px`
- `cm`
- `pt`

Types of Length Properties

- height
- width
- padding
- margin 
- border

```
------------------------------------------------
|  margin                                      |
|      ----------------------------------      |
|      | border                         |      |
|      |    ------------------------    |      |
|      |    |  padding             |    |      |
|      |    |   ----------------   |    |      |
|      |    |   | content      |   |    |      |
|      |    |   |              |   |    |      |
|      |    |   ----------------   |    |      |
|      |    |                      |    |      |
|      |    ------------------------    |      |
|      |                                |      |
|      ----------------------------------      |
|                                              |
------------------------------------------------
```

## Syntax

The format for external is the following:
```css
/* Each Selector is enclosed in { }*/
selector {
	property1: value1;
	property2: value2;
}

h1 {
	color: blue;
}
```

There are 3 different types of selectors:

1. Elements = Standard html elements `h1`
2. Class = Styles in html`.class-name`
3. ID = ID in html `#id-name`

Selectors can be combined:
```css
.selection-1.selector-2 {
	property: value;
}

/* Example */
<h1 id="selector-1" class="selector-2"
```

Can also have ancestor type selectors. Where every child in the ancestor has the same properties.
```css
.ancestor .child {
	property: value;
}

<div>
	<p> Stuff </p>
	<p> Stuff </p>
</div>

div p {
	color: red;
}

/* Everything p in the div brackets will have text colored red */
```

There also other manipulation that can be done on selectors
```
/* This means everything has these properties */
* { 
	font-family: Arial;
}
```

Can also combine selectors but using `,` between each selector.
```
.selector, .selector-2 {
	color: white;
	background-color: grey;
}
```

## Flexbox

```css
selector {
	
	display: flex;	

	flex-direction: row; /* This is set by default */ 
	flex-direction: column;

	/* Justify Is for the main axis */
	justify-content: flex-start; /* This is set by default */
	justify-content: flex-end; /* At the end of main axis */
	justify-content: center; /* At the center of main axis */
	justify-content: flex-start; /* This is set by default */
	align-content: space-between;
	align-content: space-evenly;


	/* Justify Is For The Cross axis */
	align-items: flex-start; /* At the top */
	align-items: flex-end; /* At the bottom*/
	align-items: center; /* In the Middle*/
	align-items: baseline; /* The text is aligned */

	flex-wrap: nowrap; /* Default */
	flex-wrap: wrap;

	/* Only works if wrap is enabled */
	/* Used for cross axis */
	align-content: flex-start;
	align-content: flex-end;
	align-content: center;
	align-content: space-between;
	align-content: space-evenly;

	/* To set space*/
	gap: ;

	flex-grow: 0;
	flex-shrink: 0; /* Item will never shrink */
	flex-basis: 0; /* To overwrite item */
	flex: ;zz

	/* To overwrite align-items*/
	align-self: ;

	/* To change the order */
	order: ;
}
```

```
  justify-content: flex-start;                 
  -------------------------------------------------
  |        |        |        |                    |                                              
  |        |        |        |                    |                                             
  |---------------------------                    |
  | flex-direction: row;|                         |
  |                     |                         |
  |                     |       main axis         |
  |---------------------------------------------------> 
  |                     |                         |
  |                     | cross axis              |
  |                     |                         |
  |                     |                         |
  |                    \|/                        |
  -------------------------------------------------

   justify-content: center;                                              
  -------------------------------------------------
  |                                               |
  |                                               |
  |                                               |
  |                                               |
  |           ------------------------            |
  |           |       |       |      |            |
  |           |       |       |      |            |
  |           ------------------------            |
  |                                               |
  |                                               |
  |                                               |
  -------------------------------------------------


   justify-content: flex-end;                    
  -------------------------------------------------
  |                       |       |       |       |
  |                       |       |       |       |                                                
  |                       ------------------------|
  |                                               |
  |                                               |
  |                                               |
  |---------------------------------------------------> 
  |                                               |
  |                                               |
  |                                               |
  |                                               |
  |                                               |
  -------------------------------------------------

   justify-content: space-between;               
  -------------------------------------------------
  |       |           |      |           |        |
  |       |           |      |           |        |
  |--------           --------           ---------|
  |                                               |
  |                                               |
  |                                               |
  |                                               |
  |                                               |
  |                                               |
  |                                               |                                                
  -------------------------------------------------

   justify-content: space-evenly;               
  -------------------------------------------------
  |       |      |     |      |     |      |      |
  |       |      |     |      |     |      |      |
  |       --------     --------     --------      |
  |                                               |
  |                                               |
  |                                               |
  |                                               |
  |                                               |
  |                                               |
  |                                               |                                                
  -------------------------------------------------

  -------------------------------------------------
  |        |              |                       |                                              
  |        |              | flex-direction: column|                                            
  |---------              |                       |
  |        |              |                       |
  |        |    main axis |                       |
  |-----------------------|---------------------->|      
  |        |              |     cross axis        |
  |        |              |                       |
  |---------              |                       |
  |                       |                       |                                                
  |                       |                       |                                                
  |                      \|/                      |                                                
  -------------------------------------------------
```


## Template

```
  -------------------------------------------------
  |                                               |
  |                                               |
  |                                               |
  |                                               |
  |                                               |
  |                                               |
  | justify-cotent: flex-end;                     |
  |                                               |
  |                                               |
  |                                               |                                                
  -------------------------------------------------
```
