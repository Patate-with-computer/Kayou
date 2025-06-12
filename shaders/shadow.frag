#version 120

uniform sampler2D texture;
uniform float dist;
uniform bool is_visible;
uniform bool is_shadow;
uniform float light_angle;

void main()
{
    vec2 uv = gl_TexCoord[0].st;
    float new_dist = min(100.0 / (dist * 3), 1.0);
    vec4 text = texture2D(texture, uv);
    if (is_visible && is_shadow) {
        float angle_factor = 1.0 - clamp(light_angle, 0.0, 0.8);
        float attenuation = clamp(1.0 - dist / 100.0, 0.05, 1.0);
        vec3 lit_color = text.rgb * attenuation * angle_factor;
        text.rgb = lit_color;
    } else if (!is_shadow)
        text.rgb *= new_dist;
    else
        text.rgb = vec3(0.0);

    gl_FragColor = vec4(text.rgb, text.a);
}
