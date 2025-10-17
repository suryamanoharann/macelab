from bokeh.plotting import figure, show

p = figure(title="Line Example")
p.line([1, 2, 3], [4, 6, 5], line_width=2)
show(p)
