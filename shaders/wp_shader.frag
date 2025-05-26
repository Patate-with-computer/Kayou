#version 120
uniform sampler2D texture;

uniform bool is_in_rect;
uniform bool enough;
uniform bool already;
uniform bool is_actual;

void main()
{
    vec2 uv = gl_TexCoord[0].st;
    vec4 text = texture2D(texture, uv);

    if (is_in_rect)
        text.rgb += 0.2;
    if (!enough && !already) {
        text.rgb -= 0.9;
        text.r += 0.2;
    }
    if (!already && enough) {
        text.rgb -= 0.3;
    }
    if (is_actual) {
        text.rgb -= 0.2;
        text.g += 0.4;
    }
    gl_FragColor = vec4(text.rgba);
}
