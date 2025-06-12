uniform float u_time;
uniform float dist;
uniform float cam_angle;
uniform vec2 w_size;
uniform vec2 scale_win;
uniform vec2 y_pos;
uniform vec2 player_pos;

float hash(vec2 p) {
    return fract(sin(dot(p, vec2(127.1, 311.7))) * 43758.5453);
}

float noise(vec2 p) {
    vec2 i = floor(p);
    vec2 f = fract(p);

    float a = hash(i);
    float b = hash(i + vec2(1.0, 0.0));
    float c = hash(i + vec2(0.0, 1.0));
    float d = hash(i + vec2(1.0, 1.0));

    vec2 u = f * f * (3.0 - 2.0 * f);
    return mix(a, b, u.x) +
           (c - a) * u.y * (1.0 - u.x) +
           (d - b) * u.x * u.y;
}

float noise3d(vec2 uv, float time) {
    float n1 = noise(uv + time);
    float n2 = noise(uv + vec2(5.2, 1.3) + time * 1.3);
    float n3 = noise(uv + vec2(2.7, 8.5) - time * 0.7);
    return (n1 + n2 + n3) / 2.0;
}

void main() {
    vec2 size_win = w_size * scale_win;
    vec2 uv = gl_FragCoord.xy / size_win;
    float seed = floor(dist * 0.3);
    vec2 offset = sin(vec2(seed * 0.137, seed * 0.347));
    float camera_shift = cam_angle * 2.0;
    vec2 shifted_uv = uv * 3.0 + offset + vec2(camera_shift, 0.0);
    vec2 player_offset = player_pos * 0.03;
    float n = noise3d(shifted_uv + player_offset, u_time * 0.08);
    float fog_density = smoothstep(0.3, 0.8, n);
    vec3 fog_color = vec3(0.25 + 0.2 * n,
                        0.3 + 0.25 * n,
                        0.35 + 0.15 * n);
    float dist_norm = clamp((dist) / (1000.0), 0.0, 1.0);
    float fade = pow(dist_norm, 0.5);
    float y = gl_FragCoord.y;
    float height_fade = smoothstep(50.0, 200.0, y);
    float size = (y_pos.y - y_pos.x);
    float to_fade = (size - size / 1.5) / 2.0;
    float middle = size_win.y - y_pos.x - size / 2.0;
    float boder = smoothstep(size_win.y - y_pos.x, middle + to_fade, y);
    boder *= smoothstep(size_win.y - y_pos.x - size, middle - to_fade, y);
    float alpha = fog_density * fade * height_fade * 0.4;
    if (dist_norm >= 0.995) {
        alpha = 1.0;
    }
    gl_FragColor = vec4(fog_color, alpha * boder);
}
