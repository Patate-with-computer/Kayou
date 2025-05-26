#version 120
uniform sampler2D texture;
uniform float dist;

void main()
{
    vec2 uv = gl_TexCoord[0].st;
    vec4 tex_color = texture2D(texture, uv);
    float attenuation = clamp(1.0 - dist / 600.0, 0.2, 1.0);
    vec3 lit_color = tex_color.rgb * attenuation;

    gl_FragColor = vec4(lit_color, tex_color.a);
}
